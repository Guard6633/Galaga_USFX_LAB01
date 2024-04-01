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

	
	
public:
	// Mesh de la nave enemiga
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* EnemyMesh;	

	// Propiedad para el componente de movimiento
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	UMovementPatternComponent* MovementComponent;

	// Sonido de disparo
	UPROPERTY(EditAnywhere, Category = "Audio")
	class USoundBase* FireSound;

private:
	// Declaracion de FireTimerHandle
	FTimerHandle FireTimerHandle;

public:	
	// Sets default values for this actor's properties
	AEnemyShip();

	// Atributos de la nave enemiga
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed;
	bool ChangeMove;
	float Count;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Funcion para mover la nave enemiga
	void MoveEnemy(float DeltaTime);

	void MoveEnemyPattern(float DeltaTime);

	// Funcion de disparo
	void FireShot();
}; 
