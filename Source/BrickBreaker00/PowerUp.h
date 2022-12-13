// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "PowerUp.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBREAKER00_API APowerUp : public APickUp
{
	GENERATED_BODY()

public:
	// sobre escribir el metodo ActivatePickUp
	bool ActivatePickUp() override;

protected:
	// spawn del obejeto que modifica la velocidad de actor
	UPROPERTY(EditDefaultsOnly, Category = Spawn)
		TSubclassOf<AActor> BPPowerUp;	// de tipo actor 



	
};
