// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyUIPatternBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyUIPatternBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BRICKBREAKER00_API IEnemyUIPatternBuilder
{
	GENERATED_BODY()

	// Agregar funciones de interfaz a esta clase. Esta es la clase que se heredará para implementar esta interfaz.
public:
	virtual void builMeshEnemyB() = 0;	// construir Mesh Enemy
	virtual void builVelocityB() = 0;	// construir Velocidad enemy
	virtual void buildBulletSpawnPoint() = 0;	//construir un punto de generación de balas
	virtual void buildDefenseSystem() = 0;	//construir sistema de defensa
	virtual void buildDisplacementSystem() = 0;	//construir sistema de desplazamiento
	virtual class AEnemyUIPatternBuilder* getEnemyBPattern() = 0;
};
