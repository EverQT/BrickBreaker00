// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPatternDirector.h"

// Sets default values
AEnemyPatternDirector::AEnemyPatternDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyPatternDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPatternDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyPatternDirector::ConstruirBrickEnemigo()
{
	if (!EnemyBuilder) {
		UE_LOG(LogTemp, Error, TEXT("construirBrickEnemigp(): EnemigoBuilder is NULL, asegurese de inicializar correctamente esta clase."));
		return;
	}
	EnemyBuilder->builMeshEnemyB();
	EnemyBuilder->builVelocityB();
	EnemyBuilder->buildBulletSpawnPoint();
	EnemyBuilder->buildDefenseSystem();
	EnemyBuilder->buildDisplacementSystem();
}

void AEnemyPatternDirector::setBrickEnemigoBuilder(AActor* Builder)
{
	EnemyBuilder = Cast<IEnemyUIPatternBuilder>(Builder);
	if (!EnemyBuilder) {
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, TEXT("Invalido"));
		UE_LOG(LogTemp, Error, TEXT("construirBrickEnemiga(): EnemigaBuilder is NULL, asegurese de inicializar correctamente esta clase."));
		return;
	}
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, TEXT("Se creo la nave correctamente..."));
}

AEnemyWithPattern* AEnemyPatternDirector::getBEnemigo()
{
	if (EnemyBuilder) {
		//return EnemyBuilder->getEnemyBPattern();
	}
	UE_LOG(LogTemp, Error, TEXT("getEnemiga(): Retorna NULL."));
	return nullptr;
}

