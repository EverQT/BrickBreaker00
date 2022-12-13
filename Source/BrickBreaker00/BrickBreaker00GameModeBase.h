// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Brick.h"

#include "BrickBreaker00GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBREAKER00_API ABrickBreaker00GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY()
		class ABrick* Brick;

public:
	virtual void Tick(float DeltaTime) override;
	

public:
	virtual void BeginPlay() override;
	class ABrick* brick;

void SpawnGameObject();
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> SpawnBrick;


//private:
//	FTimerHandle MemberTimer;
};
