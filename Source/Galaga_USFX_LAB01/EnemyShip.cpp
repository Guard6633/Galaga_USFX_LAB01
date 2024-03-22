// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip.h"

#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"




// Sets default values
AEnemyShip::AEnemyShip()
{
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Crear el mesh del enemigo
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	RootComponent = EnemyMesh;
    EnemyMesh->SetCollisionProfileName(TEXT("NoCollision"));
    EnemyMesh->SetStaticMesh(EnemyMeshAsset.Object);
	
	// inicializar el componente de movimiento
	MovementComponent = CreateDefaultSubobject<UMovementPatternComponent>(TEXT("MovementComponent"));
}

// Called when the game starts or when spawned
void AEnemyShip::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEnemyShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Mover el enemigo hacia el jugador 
	MoveEnemy(DeltaTime);

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