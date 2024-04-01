// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerShip.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/CollisionProfile.h"


// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	// Crea el mesh del jugador
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMesh;
	ShipMesh->SetCollisionProfileName(TEXT("Pawn"));
	ShipMesh->SetStaticMesh(ShipMeshAsset.Object);


}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	
	// Realizar el movimiento inicial de la nave solo cuando comienza el juego
	InitialMove();
}

// Called every frame
void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// movimiento inicial de la nave
void APlayerShip::InitialMove()
{
	float VelocityInitial = 10.0f;
	// Obtener la posicion actual de la nave
	FVector CurrentLocation = GetActorLocation();
	// Avatar hacia adelante con la velocidad inicial
	CurrentLocation += GetActorForwardVector() + VelocityInitial;
	// establecer la nueva posicion de la nave
	SetActorLocation(CurrentLocation);
}