// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "SpawnEnemy.h"

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_LAB01GameMode.generated.h"

class APlayerShip;

UCLASS(MinimalAPI)
class AGalaga_USFX_LAB01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_LAB01GameMode();

protected:
	virtual void BeginPlay() override;

	// Spawn de naves enemigas
	ASpawnEnemy* SpawnEnemy;

public: 
	APlayerShip* PlayerShip;


};



