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

	// Crea un nuevo vector con direccion al jugador en el eje X
	FVector NewLocation = FVector(CurrentLocation.X - Speed * DeltaTime, CurrentLocation.Y, CurrentLocation.Z);

	// Establece la nueva posicion del enemigo
	SetActorLocation(NewLocation);

	//// Obtener la posicion actual del actor
	//FVector CurrentLocation = GetActorLocation();

	//// Genera nuevas coordenadas para el enemigo
	//float NewX = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;
	//float NewY = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;

	//// Crea un nuevo vector con direccion al jugador
	//FVector NewLocation = FVector(CurrentLocation.X + NewX, CurrentLocation.Y + NewY, CurrentLocation.Z);

	//// Establece la nueva posicion del enemigo
	//SetActorLocation(NewLocation);
	
}