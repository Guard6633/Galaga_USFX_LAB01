// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_LAB01GameMode.h"
#include "Galaga_USFX_LAB01Pawn.h"
#include "EnemyShipHunter.h"
#include "EnemyShipTransport.h"
#include "EnemyShipSupplier.h"
#include "EnemyShipMother.h"
#include "EnemyShip.h"
#include "SpawnEnemy.h"
#include "PlayerShip.h"


AGalaga_USFX_LAB01GameMode::AGalaga_USFX_LAB01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_LAB01Pawn::StaticClass();

}

void AGalaga_USFX_LAB01GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Spawn de PlayerShip
	UWorld* const World = GetWorld();
	// Ubicacion de la nave del jugador
	FVector CoordPlayerShip = FVector(-1800.0f, 0.0f, 200.0f);
	FRotator RotationShip = FRotator(0.0f, 0.0f, 0.0f);

	if (World != nullptr)
	{
		APlayerShip* NewPlayerShip = World->SpawnActor<APlayerShip>(CoordPlayerShip, RotationShip);
		if (NewPlayerShip)
		{
			PlayerShip = NewPlayerShip;
		}
	}

	// Crear una instancia de ASpawnEnemy
	SpawnEnemy = GetWorld()->SpawnActor<ASpawnEnemy>();
	// Llamar a la funcion SpawnFromPoints
	SpawnEnemy->SpawnFromPoints();

}

