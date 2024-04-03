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

	// Llenar el contenedor con los tipos de naves enemigas
	EnemyShips.Add(AEnemyShip::StaticClass());
	EnemyShips.Add(AEnemyShipHunter::StaticClass());
	EnemyShips.Add(AEnemyShipMother::StaticClass());
	EnemyShips.Add(AEnemyShipSupplier::StaticClass());
	EnemyShips.Add(AEnemyShipTransport::StaticClass());

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

void ASpawnEnemy::SpawnFromPoints()
{
	// Asignar las posiciones a las naves
	AssignPositionToShip();

	// Recorrer el contenedor y spawnear las naves
	for (auto& Elem : ShipContainer1)
	{
		FVector SpawnLocation = Elem.Key;
		AEnemyShip* NewEnemyShip = GetWorld()->SpawnActor<AEnemyShip>(EnemyShips[0], SpawnLocation, FRotator::ZeroRotator);
		Elem.Value = NewEnemyShip;
	}

	for (auto& Elem : ShipContainer2)
	{
		FVector SpawnLocation = Elem.Key;
		AEnemyShip* NewEnemyShip = GetWorld()->SpawnActor<AEnemyShip>(EnemyShips[0], SpawnLocation, FRotator::ZeroRotator);
		Elem.Value = NewEnemyShip;
	}
}

void ASpawnEnemy::AssignPositionToShip()
{
	// Ubicacion destino
	FVector CoordDestination;
	bool flag = true;

	// Seleccionar una nave aleatoria del contenedor
	int RandomIndex = FMath::RandRange(0, EnemyShips.Num() - 1);
	TSubclassOf<AEnemyShip> NewEnemyShipClass = EnemyShips[RandomIndex];

	int randomDestination = FMath::RandRange(0, 4);

	switch (randomDestination)
	{
		
		case 0:
			CoordDestination = FVector(1600.0f, 800.0f, 200.0f);
			for (int i = 0; i < 8; i++)
			{
				
				AEnemyShip* NewEnemyShip;
				if (flag)
				{
					ShipContainer1.Add(CoordDestination, NewEnemyShip);
					CoordDestination.Y *= -1;
					flag = false;
				}
				else {
					ShipContainer2.Add(CoordDestination, NewEnemyShip);
					// distancia entre naves
					CoordDestination.Y += 200.0f;
					CoordDestination.Y *= -1;
					flag = true;
				}
			}
			break;
		case 1:
			CoordDestination = FVector(1400.0f, 1200.0f, 200.0f);
			for (int i = 0; i < 12; i++)
			{

				AEnemyShip* NewEnemyShip;
				if (flag)
				{
					ShipContainer1.Add(CoordDestination, NewEnemyShip);
					CoordDestination.Y *= -1;
					flag = false;
				}
				else {
					ShipContainer2.Add(CoordDestination, NewEnemyShip);
					// distancia entre naves
					CoordDestination.Y += 200.0f;
					CoordDestination.Y *= -1;
					flag = true;
				}
			}
			break;
		case 2:
			CoordDestination = FVector(1200.0f, 1200.0f, 200.0f);
			for (int i = 0; i < 12; i++)
			{

				AEnemyShip* NewEnemyShip;
				if (flag)
				{
					ShipContainer1.Add(CoordDestination, NewEnemyShip);
					CoordDestination.Y *= -1;
					flag = false;
				}
				else {
					ShipContainer2.Add(CoordDestination, NewEnemyShip);
					// distancia entre naves
					CoordDestination.Y += 200.0f;
					CoordDestination.Y *= -1;
					flag = true;
				}
			}
			break;
		case 3:
			CoordDestination = FVector(1000.0f, 1600.0f, 200.0f);
			for (int i = 0; i < 16; i++)
			{

				AEnemyShip* NewEnemyShip;
				if (flag)
				{
					ShipContainer1.Add(CoordDestination, NewEnemyShip);
					CoordDestination.Y *= -1;
					flag = false;
				}
				else {
					ShipContainer2.Add(CoordDestination, NewEnemyShip);
					// distancia entre naves
					CoordDestination.Y += 200.0f;
					CoordDestination.Y *= -1;
					flag = true;
				}
			}
			break;
		case 4:
			CoordDestination = FVector(800.0f, 1600.0f, 200.0f);
			for (int i = 0; i < 16; i++)
			{

				AEnemyShip* NewEnemyShip;
				if (flag)
				{
					ShipContainer1.Add(CoordDestination, NewEnemyShip);
					CoordDestination.Y *= -1;
					flag = false;
				}
				else {
					ShipContainer2.Add(CoordDestination, NewEnemyShip);
					// distancia entre naves
					CoordDestination.Y += 200.0f;
					CoordDestination.Y *= -1;
					flag = true;
				}
			}
			break;
	}
}