// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_LAB01Pawn.h"
#include "Galaga_USFX_LAB01Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

const FName AGalaga_USFX_LAB01Pawn::MoveForwardBinding("MoveForward");
const FName AGalaga_USFX_LAB01Pawn::MoveRightBinding("MoveRight");
const FName AGalaga_USFX_LAB01Pawn::FireForwardBinding("FireForward");
const FName AGalaga_USFX_LAB01Pawn::FireRightBinding("FireRight");

AGalaga_USFX_LAB01Pawn::AGalaga_USFX_LAB01Pawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	//// Create a camera boom...
	//CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	//CameraBoom->SetupAttachment(RootComponent);
	//CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	//CameraBoom->TargetArmLength = 1200.f;
	//CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	//CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	/*CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);*/
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm
	// Establecer una posicion fija para la camara
	CameraComponent->SetWorldLocation(FVector(0.0f, 0.0f, 4000.0f));
	CameraComponent->SetWorldRotation(FRotator(-90.0f, 0.0f, 0.0f));

	// Movement
	MoveSpeed = 750.0f;
	RollFactor = 45.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.75f;
	bCanFire = true;
}

void AGalaga_USFX_LAB01Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
}

void AGalaga_USFX_LAB01Pawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	//// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	//const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	//// Calculate  movement
	//const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	//// If non-zero size, move this actor
	//if (Movement.SizeSquared() > 0.0f)
	//{
	//	const FRotator NewRotation = Movement.Rotation();
	//	FHitResult Hit(1.f);
	//	RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	//	
	//	if (Hit.IsValidBlockingHit())
	//	{
	//		const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
	//		const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
	//		RootComponent->MoveComponent(Deflection, NewRotation, true);
	//	}
	//}
	
	// Obtener valores de entrada del jugador para movimiento
	const float MoveForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float MoveRightValue = GetInputAxisValue(MoveRightBinding);

	// Calcular la rotación deseada basada en las teclas presionadas
	FRotator DesiredRotation = FRotator(0.f, 0.f, 0.f);
	if (MoveForwardValue > 0)
	{
		DesiredRotation.Pitch = -20.f; 
	}
	else if (MoveForwardValue < 0)
	{
		DesiredRotation.Pitch = 20.f;
	}

	if (MoveRightValue > 0)
	{
		DesiredRotation.Yaw = 30.f; 
	}
	else if (MoveRightValue < 0)
	{
		DesiredRotation.Yaw = -30.f;
	}

	// Aplicar la rotación deseada a la nave
	// Se asume que ShipMeshComponent es el componente de la nave
	ShipMeshComponent->AddRelativeRotation(DesiredRotation);

	// Calcular el movimiento basado en la rotación actual de la nave
	FVector Movement = FVector(MoveForwardValue, MoveRightValue, 0.f) * MoveSpeed * DeltaSeconds;

	// Si hay un movimiento, aplicar el movimiento y rotación a la nave
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

	// Restablecer la rotación en Z a 0
	DesiredRotation.Roll = 0.f;
	ShipMeshComponent->SetRelativeRotation(DesiredRotation);

	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void AGalaga_USFX_LAB01Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AGalaga_USFX_LAB01Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_USFX_LAB01Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGalaga_USFX_LAB01Pawn::ShotTimerExpired()
{
	bCanFire = true;
}

