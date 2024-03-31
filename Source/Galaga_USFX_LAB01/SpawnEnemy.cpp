// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEnemy.h"
#include "EnemyShip.h"
#include "EnemyShipHunter.h"
#include "EnemyShipTransport.h"
#include "EnemyShipSupplier.h"
#include "EnemyShipMother.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"


// Sets default values
ASpawnEnemy::ASpawnEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SpawnMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	// Mesh del spawn
	SpawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnMesh"));
	RootComponent = SpawnMesh;
	SpawnMesh->SetStaticMesh(SpawnMeshAsset.Object);

}

// Called when the game starts or when spawned
void ASpawnEnemy::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ASpawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnEnemy::FillSpawnPoints()
{
	// Ubicacion de la nave enemiga
	FVector CoordEnemyShip;
	FRotator RotationShip;

	UWorld* const World = GetWorld();

	if (World != nullptr)
	{

		for (int i = 0; i < 20; i++)
		{	
			int randomPoint = FMath::RandRange(0, 5);
			switch (randomPoint)
			{
			case 0:
				CoordEnemyShip = FVector(1900.0f, 100.0f, 200.0f);
				RotationShip = FRotator(0.0f, 180.0f, 0.0f);
				break;
			case 1:
				CoordEnemyShip = FVector(1900.0f, -100.0f, 200.0f);
				RotationShip = FRotator(0.0f, 180.0f, 0.0f);
				break;
			case 2:
				CoordEnemyShip = FVector(100.0f, -1900.0f, 200.0f);
				RotationShip = FRotator(0.0f, 90.0f, 0.0f);
				break;
			case 3:
				CoordEnemyShip = FVector(-100.0f, -1900.0f, 200.0f);
				RotationShip = FRotator(0.0f, 90.0f, 0.0f);
				break;
			case 4:
				CoordEnemyShip = FVector(100.0f, 1900.0f, 200.0f);
				RotationShip = FRotator(0.0f, 270.0f, 0.0f);
				break;
			case 5:
				CoordEnemyShip = FVector(-100.0f, 1900.0f, 200.0f);
				RotationShip = FRotator(0.0f, 270.0f, 0.0f);
				break;
			}

			int RandomEnemyType = FMath::RandRange(0, 4);
			AEnemyShip* NewEnemyShip = nullptr;
			switch (RandomEnemyType)
			{
			case 0:
				NewEnemyShip = World->SpawnActor<AEnemyShip>(CoordEnemyShip, RotationShip);
				break;
			case 1:
				NewEnemyShip = World->SpawnActor<AEnemyShipHunter>(CoordEnemyShip, RotationShip);
				break;
			case 2:
				NewEnemyShip = World->SpawnActor<AEnemyShipTransport>(CoordEnemyShip, RotationShip);
				break;
			case 3:
				NewEnemyShip = World->SpawnActor<AEnemyShipSupplier>(CoordEnemyShip, RotationShip);
				break;
			case 4:
				NewEnemyShip = World->SpawnActor<AEnemyShipMother>(CoordEnemyShip, RotationShip);
				break;
			}

			if (NewEnemyShip)
			{
				// Almacenar el tipo de nave enemiga y el vector destino en el TMap
				SpawnPoints.Add(CoordEnemyShip, NewEnemyShip);
			}
			
		}
	}
}