// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_LAB01GameMode.h"
#include "Galaga_USFX_LAB01Pawn.h"
#include "EnemyShipHunter.h"
#include "EnemyShipTransport.h"
#include "EnemyShipSupplier.h"
#include "EnemyShipMother.h"
#include "EnemyShip.h"


AGalaga_USFX_LAB01GameMode::AGalaga_USFX_LAB01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_LAB01Pawn::StaticClass();

}

void AGalaga_USFX_LAB01GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Ubicacion de la nave enemiga
	FVector CoordEnemyShip = FVector(1900.0f, -1800.0f, 200.0f);
	FVector CoordActEnemyShip = CoordEnemyShip;
	FRotator RotaionShip = FRotator(0.0f, 180.0f, 0.0f);

	UWorld* const World = GetWorld();

	if (World != nullptr)
	{
		for (int i = 0; i < 30; i++)
		{
			int RandomEnemyType = FMath::RandRange(0, 4);
			AEnemyShip* NewEnemyShip = nullptr;

			switch (RandomEnemyType)
			{
			case 0:
				NewEnemyShip = World->SpawnActor<AEnemyShip>(CoordActEnemyShip, RotaionShip);
				break;
			case 1:
				NewEnemyShip = World->SpawnActor<AEnemyShipHunter>(CoordActEnemyShip, RotaionShip);
				break;
			case 2:
				NewEnemyShip = World->SpawnActor<AEnemyShipTransport>(CoordActEnemyShip, RotaionShip);
				break;
			case 3:
				NewEnemyShip = World->SpawnActor<AEnemyShipSupplier>(CoordActEnemyShip, RotaionShip);
				break;
			case 4:
				NewEnemyShip = World->SpawnActor<AEnemyShipMother>(CoordActEnemyShip, RotaionShip);
				break;
			}

			if (NewEnemyShip)
			{
				EnemyShips.Add(NewEnemyShip);
			}

			CoordActEnemyShip.Y += 120.0f; // Ajustar la posición de la siguiente nave enemiga

			// Si el enemigo se sale del mapa, vuelve a la posición inicial
			if (CoordActEnemyShip.Y > 1800.0f)
			{
				CoordActEnemyShip.Y = CoordEnemyShip.Y;
				CoordActEnemyShip.X -= 200.0f;
			}
		}
	}
}

