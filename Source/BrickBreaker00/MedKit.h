// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "MedKit.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBREAKER00_API AMedKit : public APickUp
{
	GENERATED_BODY()

public:
	bool ActivatePickUp() override;

	//bool ActivatePickUpSpeed() override;

protected:
	// cuanto recuperar la vida
	UPROPERTY(VisibleDefaultsOnly, Category = Stats) float Healt{ 25.0f };


};
