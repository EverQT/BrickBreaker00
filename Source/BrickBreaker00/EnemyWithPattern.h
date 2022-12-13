// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Paddle.h"
#include "EnemyWithPattern.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBREAKER00_API AEnemyWithPattern : public APaddle
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Enemigo con Patron")
		UStaticMeshComponent* MeshBrickEnemy;
	UPROPERTY(EditAnywhere, Category = "Enemigo con Patron")
		float VelocityBrick;
	UPROPERTY(EditAnywhere, Category = "Enemigo con Patron")
		USceneComponent* BulletSpawnPoint;
	UPROPERTY(EditAnywhere, Category = "Enemigo con Patron")
		FString DefenseSystem;
	UPROPERTY(EditAnywhere, Category = "Enemigo con Patron")
		FString DisplacementSystem;

public:
	AEnemyWithPattern();

	// accesores
	void setMeshBrickEnemy(UStaticMeshComponent* _MeshBrickEnemy) { MeshBrickEnemy = _MeshBrickEnemy; }
	void setVelocityBrick(float _VelocityBrick) { VelocityBrick = _VelocityBrick; }
	void setBulletSpawnPoint(USceneComponent* _BulletSpawnPoint) { BulletSpawnPoint = _BulletSpawnPoint; }
	void setDefenseSystem(FString _DefenseSystem) { DefenseSystem = _DefenseSystem; }
	void setDisplacementSystem(FString _DisplacementSystem) { DisplacementSystem = _DisplacementSystem; }
	void CharacteristicsEnemyBrick();	// caracteristicas del enemigo

};
