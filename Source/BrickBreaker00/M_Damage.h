// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "M_Damage.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBREAKER00_API AM_Damage : public APickUp
{
	GENERATED_BODY()

public:
	bool ActivatePickUp() override;

protected:
	// cuanto recuperar la vida
	UPROPERTY(VisibleDefaultsOnly, Category = Stats) float Health{ -50.0f };
	
};
