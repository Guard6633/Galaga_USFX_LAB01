// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementPatternComponent.h"

// Sets default values for this component's properties
UMovementPatternComponent::UMovementPatternComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// definir los valores por defecto
	Speed = 200.0f;
    ElapsedTime = 0.0f;
	ChangeMode = true;
	ContMove = 0.0f;
	
}


// Called when the game starts
void UMovementPatternComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMovementPatternComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Llama a la funcion de movimiento
	MovePattern(DeltaTime);

	// Cambiar de modo de movimiento
	if (ChangeMode)
	{
		MovePattern(DeltaTime);
		ContMove += DeltaTime;
		if (ContMove >= 10.0f)
		{
			ChangeMode = false;
			ContMove = 0.0f;
		}
	}
	else
	{
		ContMove += DeltaTime;
		if (ContMove >= 20.0f)
		{
			ChangeMode = true;
			ContMove = 0.0f;
		}
	}
}

void UMovementPatternComponent::MovePattern(float DeltaTime)
{
	// Patron de movimiento de todas las naves
	AActor *Parent = GetOwner();
	if (Parent)
	{
		 // Calcular la nueva posición basada en el tiempo
		FVector NewLocation = Parent->GetActorLocation();

		float DeltaY = Speed * DeltaTime;

		// Definir el tiempo para cambiar de dirección
		float ChangeDirectionTime = 3.0f; 

		// Actualizar el contador de tiempo
		ElapsedTime += DeltaTime;

		// Verificar si es tiempo de cambiar de dirección
		if (ElapsedTime >= ChangeDirectionTime)
		{
			// Cambiar de dirección multiplicando la velocidad por -1
			Speed *= -1.0f;
			ElapsedTime = 0.0f; // Reiniciar el contador de tiempo
		}

		// Actualizar la posición Y de la nave
		NewLocation.Y += DeltaY;

		// Establecer la nueva posición de la nave
		Parent->SetActorLocation(NewLocation);

	}
}

