// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShipHunter.h"

// Called when the game starts or when spawned
void AEnemyShipHunter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyShipHunter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Mover el enemigo
	MoveEnemy(DeltaTime);
}

// Cmabiar el mesh de la clase hija
AEnemyShipHunter::AEnemyShipHunter()
{
	// Crear el mesh del enemigo
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	EnemyMesh->SetStaticMesh(EnemyMeshAsset.Object);

}

// Movimiento de la nave hunter (sigue al jugador)
void AEnemyShipHunter::MoveEnemy(float DeltaTime)
{
	// Obtener la posicion actual del actor
	FVector CurrentLocation = GetActorLocation();

	// Obtener la posición del jugador
	FVector PlayerLocation = FVector(-800.0f, 0.0f, 200.0f);

	// Calcular la dirección hacia el jugador
	FVector Direction = (PlayerLocation - CurrentLocation).GetSafeNormal();

	// Calcular la nueva posición
	FVector NewLocation = CurrentLocation + (Direction * Speed * DeltaTime);

	// Establece la nueva posicion del enemigo
	SetActorLocation(NewLocation);
}