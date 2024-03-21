// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyShip.h"
#include "EnemyShipSupplier.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB01_API AEnemyShipSupplier : public AEnemyShip
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


	// Cambiar el mesh de la clase hija
public:
	AEnemyShipSupplier();

public:
	// Cambiar el movimiento de la clase hija
	virtual void MoveEnemy(float Deltatime);
};
