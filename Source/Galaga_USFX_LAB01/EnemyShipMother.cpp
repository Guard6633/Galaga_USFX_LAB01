// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShipMother.h"

// Called when the game starts or when spawned
void AEnemyShipMother::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEnemyShipMother::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Mover el enemigo
	MoveEnemy(DeltaTime);
}

// Cmabiar el mesh de la clase hija
AEnemyShipMother::AEnemyShipMother()
{
	// Crear el mesh del enemigo
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	EnemyMesh->SetStaticMesh(EnemyMeshAsset.Object);

}

// Movimiento de la nave Mother (Se mueve en Y de ida y vuelta)
void AEnemyShipMother::MoveEnemy(float DeltaTime)
{
	// Obtener la posicion actual del actor
	FVector CurrentLocation = GetActorLocation();

	// Vector de movimiento en Y
	FVector MovementY = FVector(0.0f, Speed * DeltaTime, 0.0f);

	// Calcular la nueva posicion del enemigo
	FVector NewLocation = CurrentLocation + MovementY;

	// Establece la nueva posicion del enemigo
	SetActorLocation(NewLocation);
}