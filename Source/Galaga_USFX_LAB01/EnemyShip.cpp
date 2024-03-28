// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip.h"

#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Engine/CollisionProfile.h"
#include "Galaga_USFX_LAB01Projectile.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"




// Sets default values
AEnemyShip::AEnemyShip()
{
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	// Crear el componente del Mesh
	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	RootComponent = EnemyMesh;
    EnemyMesh->SetCollisionProfileName(TEXT("NoCollision"));
    EnemyMesh->SetStaticMesh(EnemyMeshAsset.Object);
	
	// inicializar el componente de movimiento
	MovementComponent = CreateDefaultSubobject<UMovementPatternComponent>(TEXT("MovementComponent"));

    // Sonido de disparo
    static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("SoundWave'/Game/TwinStick/Audio/TwinStickFire.TwinStickFire'"));
    FireSound = FireAudio.Object;

	// Valores iniciales
	Speed = 400.0f;
    ChangeMove = true;
    Count = 0.0f;

}

// Called when the game starts or when spawned
void AEnemyShip::BeginPlay()
{
	Super::BeginPlay();

    // Temporizador de disparo
    GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AEnemyShip::FireShot, 5.0f, true);
}

// Called every frame
void AEnemyShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // Mover el enemigo hacia el jugador 
	//MoveEnemy(DeltaTime);
	// La nave no se mueve durante 10 segundos y luego se mueve hacia abajo
    if (ChangeMove == true)
    {
        Count += DeltaTime;
        if (Count >= 10.0f)
        {
            ChangeMove = false;
            Count = 0.0f;
        }
    }
    else
    {
        MoveEnemy(DeltaTime);
        Count += DeltaTime;
        if (Count >= 6.0f)
        {
            ChangeMove = true;
            Count = 0.0f;
        }
    }
    //// Disparar cada 5 segundos
    //static float FireInterval = 5.0f;
    //static float TimeSinceLastFire = 0.0f;
    //TimeSinceLastFire += DeltaTime;
    //if (TimeSinceLastFire >= FireInterval)
    //{
    //    FireShot();
    //    TimeSinceLastFire = 0.0f;
    //}
}

// Movimiento en linea recta hacia abajo en el eje X
void AEnemyShip::MoveEnemy(float DeltaTime)
{
	// Obtener la posicion actual del actor
	FVector CurrentLocation = GetActorLocation();

	// Calcular la nueva posición
	FVector NewLocation = CurrentLocation + (FVector(-1.0f, 0.0f, 0.0f) * Speed * DeltaTime);

	// Establece la nueva posicion del enemigo
	SetActorLocation(NewLocation);

	// Si el enemigo se sale del mapa, vuelve a la posición inicial
	if (NewLocation.X < -1000.0f)
	{
		SetActorLocation(FVector(1000.0f, 0.0f, 200.0f));
	}
    
}

// Movimiento con el componente de movimiento
void AEnemyShip::MoveEnemyPattern(float DeltaTime)
{
	// Llamar al componente de movimiento
	MovementComponent->TickComponent(DeltaTime, ELevelTick::LEVELTICK_All, nullptr);
}

void AEnemyShip::FireShot()
{
    FVector FireDirection = FVector(-1.0f, 0.0f, 0.0f);
    FVector SpawnLocation = GetActorLocation() + FireDirection * 1.0f;

    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        AActor* owner = this;
        World->SpawnActor<AGalaga_USFX_LAB01Projectile>(SpawnLocation, FRotator::ZeroRotator);
    }

    if (FireSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
    }
}