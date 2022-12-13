// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// metodo de vida
bool UHealthComponent::Heal(float amount)
{
	if (Life >= MAX_LIFE)
		return false;

	Life = FMath::Clamp(Life + amount, 0.0f, MAX_LIFE); // clamp limitar menores a 0 o mayores a 100

	return true;
}

bool UHealthComponent::ToDamage(float amount)
{
	if (Life >= MAX_LIFE)
		Life = FMath::Clamp(Life + amount, 0.0f, MAX_LIFE);
		return true;


	//	return true;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

