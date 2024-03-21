// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyShip.h"
#include "EnemyShipHunter.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB01_API AEnemyShipHunter : public AEnemyShip
{
	GENERATED_BODY()

	// nuevos valores de la clase hija
	float Speed = 100.0f;

	// Cambiar el mesh de la clase hija
public:
	AEnemyShipHunter();

public:
	// Cambiar el movimiento de la clase hija
	virtual void MoveEnemy(float Deltatime);

};
