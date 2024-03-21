// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementPatternComponent.h"

// Sets default values for this component's properties
UMovementPatternComponent::UMovementPatternComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovementPatternComponent::BeginPlay()
{
	Super::BeginPlay();

	// TMap para almacenar los tipos de enemigos y sus puntos de spawn
    TMap<FString, UClass*> EnemyShips;
    TArray<FVector> SpawnPoints;

	// Tipos de naves enemigas
	//EnemyShips.Add("Hunter", EnemyShipHunter::StaticClass());
	//EnemyShips.Add("Mother", EnemyShipMotherr::StaticClass());
	//EnemyShips.Add("Spy", EnemyShipSpy::StaticClass());
	//EnemyShips.Add("Supplier", EnemyShipSupplier::StaticClass());
	//EnemyShips.Add("Transport", EnemyShipTransport::StaticClass());

	//

	//// Puntos de spawn para los enemigos
	//SpawnPoints.Add(FVector(0, 0, 0));
	//SpawnPoints.Add(FVector(100, 0, 0));
	//SpawnPoints.Add(FVector(200, 0, 0));
	//SpawnPoints.Add(FVector(300, 0, 0));
	//SpawnPoints.Add(FVector(400, 0, 0));
	//


	// ...
	
}


// Called every frame
void UMovementPatternComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

