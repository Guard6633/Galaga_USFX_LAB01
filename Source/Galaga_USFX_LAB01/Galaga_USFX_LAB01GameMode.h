// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_LAB01GameMode.generated.h"

class AEnemyShip;
class AEnemyShipHunter;
class AEnemyShipMother;
class AEnemyShipSpy;
class AEnemyShipSupplier;
class AEnemyShipTransport;

UCLASS(MinimalAPI)
class AGalaga_USFX_LAB01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_LAB01GameMode();

protected:
	virtual void BeginPlay() override;

public:
	AEnemyShip* EnemyShip;
	AEnemyShipHunter* EnemyShipHunter;
	AEnemyShipMother* EnemyShipMother;
	AEnemyShipSpy* EnemyShipSpy;
	AEnemyShipSupplier* EnemyShipSupplier;
	AEnemyShipTransport* EnemyShipTransport;

public:
	UPROPERTY(EditAnywhere, Category = "Enemy")
	TMap<FVector, AEnemyShip*> EnemyShips;
};



