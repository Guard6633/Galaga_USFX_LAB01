// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovementPatternComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_LAB01_API UMovementPatternComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovementPatternComponent();

	// Valores de movimiento de las naves
	float Speed;
	float ElapsedTime;
	bool ChangeMode;
	float ContMove;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Funcion para mover la nave enemiga
	void MovePattern(float DeltaTime);

	
};
