// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyShip.h"
#include "EnemyShipMother.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB01_API AEnemyShipMother : public AEnemyShip
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Cambiar los valores de la clase hija
public:
	float Speed = 50.0f;

	// Cambiar el mesh de la clase hija
public:
	AEnemyShipMother();

public:
	// Cambiar el movimiento de la clase hija
	virtual void MoveEnemy(float Deltatime);
	
};
