// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyUI.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyUI : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BRICKBREAKER00_API IEnemyUI
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// funciones virtuales puras la projectil
	virtual void Projectiles() = 0;

};
