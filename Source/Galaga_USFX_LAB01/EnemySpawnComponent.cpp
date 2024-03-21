// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawnComponent.h"
#include "EnemyShip.h"
#include "EnemyShipHunter.h"
#include "EnemyShipMother.h"
#include "EnemyShipSpy.h"
#include "EnemyShipSupplier.h"

// Sets default values for this component's properties
UEnemySpawnComponent::UEnemySpawnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Agrega tipos de enemigos al TMap
    EnemySpawnPoints.Add("EnemyType1", AEnemyShip::StaticClass());
    EnemySpawnPoints.Add("EnemyType2", AEnemyShipHunter::StaticClass());
    EnemySpawnPoints.Add("EnemyType3", AEnemyShipMother::StaticClass());
    EnemySpawnPoints.Add("EnemyType4", AEnemyShipSpy::StaticClass());
    EnemySpawnPoints.Add("EnemyType5", AEnemyShipSupplier::StaticClass());
    
}


// Called when the game starts
void UEnemySpawnComponent::BeginPlay()
{
    Super::BeginPlay();

    // Espawnear enemigos en una fila al principio del juego
    UWorld* World = GetWorld();

    if (World)
    {
        // Asume que EnemyType es una FString que contiene el tipo de enemigo que quieres spawnear
        FString EnemyType = "EnemyType1";

        // Comprueba si la clave existe en el TMap antes de intentar acceder a ella
        if (EnemySpawnPoints.Contains(EnemyType))
        {
            // Obtiene la subclase de la nave enemiga del TMap
            TSubclassOf<AEnemyShip> EnemySubclass = EnemySpawnPoints[EnemyType];

            // Define la ubicación donde quieres spawnear la nave enemiga
            FVector SpawnLocation = FVector(100.0f, 200.0f, 300.0f); // Reemplaza esto con la ubicación deseada

            // Define la rotación de la nave enemiga
            FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f); // Reemplaza esto con la rotación deseada

            // Crea una FTransform con la ubicación y la rotación deseadas
            FTransform SpawnTransform;
            SpawnTransform.SetLocation(SpawnLocation);
            SpawnTransform.SetRotation(SpawnRotation.Quaternion());


            // Spawnea la nave enemiga
            AEnemyShip* SpawnedEnemy = World->SpawnActor<AEnemyShip>(EnemySubclass, SpawnTransform);
        }
    }

	
 
}


// Called every frame
void UEnemySpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

