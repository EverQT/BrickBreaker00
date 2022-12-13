// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyUIPatternBuilder.h"
#include "EnemyPatternDirector.generated.h"

UCLASS()
class BRICKBREAKER00_API AEnemyPatternDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyPatternDirector();

private:
	IEnemyUIPatternBuilder* EnemyBuilder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ConstruirBrickEnemigo();
	void setBrickEnemigoBuilder(AActor* Builder);
	class AEnemyWithPattern* getBEnemigo();


};
