// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyShip.h"
#include "EnemyShipHunter.h"
#include "EnemySpawnComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_LAB01_API UEnemySpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemySpawnComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// TMap para los puntos de spawn
	UPROPERTY(EditAnywhere, Category = "EnemySpawn")
	TMap<FString, TSubclassOf<AEnemyShip>> EnemySpawnPoints;
	
};
