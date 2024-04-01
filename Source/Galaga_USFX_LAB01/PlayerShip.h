// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerShip.generated.h"

UCLASS()
class GALAGA_USFX_LAB01_API APlayerShip : public AActor
{
	GENERATED_BODY()

public: 
	// Mesh para el jugador
	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* ShipMesh;

public:	
	// Sets default values for this actor's properties
	APlayerShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Funcion del movimiento de la nave al aparecer
	void InitialMove();

};
