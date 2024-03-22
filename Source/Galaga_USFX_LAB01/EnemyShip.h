// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovementPatternComponent.h"
#include "EnemyShip.generated.h"

UCLASS()
class GALAGA_USFX_LAB01_API AEnemyShip : public AActor
{
	GENERATED_BODY()

	
	// Aqui se cambia el MESH de la clase padre
public: 
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* EnemyMesh;	

	//Propiedad para el componente de movimiento
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	UMovementPatternComponent* MovementComponent;

public:	
	// Sets default values for this actor's properties
	AEnemyShip();

	// Velocidad de la nave enemiga
	// UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 150.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Funcion para mover la nave enemiga
	void MoveEnemy(float DeltaTime);

	// Funcion de movimiento con el componente de movimiento
	void MoveEnemyPattern(float DeltaTime);
};
