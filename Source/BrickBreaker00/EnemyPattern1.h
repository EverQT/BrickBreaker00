// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyUIPatternBuilder.h"
#include "EnemyPattern1.generated.h"

UCLASS()
class BRICKBREAKER00_API AEnemyPattern1 : public APawn, public IEnemyUIPatternBuilder
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPattern1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// componentes
	UPROPERTY(EditAnywhere, Category = "Componentes")
		UStaticMeshComponent* MeshEnemy;
	// --
	UPROPERTY(EditAnywhere, Category = "Componentes")
		USceneComponent* BulletSpawnPoint;

private:
	UPROPERTY(EditAnywhere, Category = "Nave Enemiga con patron 1")
	class	AEnemyWithPattern* PatternEnemyB1;

public:
	// sobrecargamos funciones
	virtual void builMeshEnemyB() override;
	virtual void builVelocityB() override;
	virtual void buildBulletSpawnPoint() override;
	virtual void buildDefenseSystem() override;
	virtual void buildDisplacementSystem() override;
	virtual class AEnemyUIPatternBuilder* getEnemyBPattern() override;

};
