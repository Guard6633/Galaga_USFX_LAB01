 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnEnemy.generated.h"

class AEnemyShip;
class AEnemyShipHunter;
class AEnemyShipMother;
class AEnemyShipSpy;
class AEnemyShipSupplier;
class AEnemyShipTransport;

UCLASS()
class GALAGA_USFX_LAB01_API ASpawnEnemy : public AActor
{
	GENERATED_BODY()
	
	// Mesh del spawn point
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SpawnMesh;

	

public:	
	// Sets default values for this actor's properties
	ASpawnEnemy();

public:
	AEnemyShip* EnemyShip;
	AEnemyShipHunter* EnemyShipHunter;
	AEnemyShipMother* EnemyShipMother;
	AEnemyShipSpy* EnemyShipSpy;
	AEnemyShipSupplier* EnemyShipSupplier;
	AEnemyShipTransport* EnemyShipTransport;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Puntos de destino y naves enemigas a spawnear
	UPROPERTY(EditAnywhere, category = "Spawner")
	TMap<FVector, AEnemyShip*> SpawnPoints;

	// Metodo para llenar el contenedor de naves y sus puntos de destino
	void FillSpawnPoints();

};
