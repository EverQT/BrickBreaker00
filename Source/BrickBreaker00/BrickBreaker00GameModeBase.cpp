// Copyright Epic Games, Inc. All Rights Reserved.


#include "BrickBreaker00GameModeBase.h"
#include <Runtime\Engine\Classes\Engine\World.h>

void ABrickBreaker00GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 1; i++)
	{
		SpawnGameObject();

	}

}

void ABrickBreaker00GameModeBase::SpawnGameObject()
{

	FVector Location(0.0f, FMath::RandRange(-60.0f, 0.0f), 310.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	GetWorld()->SpawnActor<AActor>(SpawnBrick, Location, Rotation);


}

void ABrickBreaker00GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
