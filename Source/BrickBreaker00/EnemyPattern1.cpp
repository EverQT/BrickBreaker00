// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPattern1.h"
#include "EnemyUIPatternBuilder.h"
#include "EnemyWithPattern.h"

// Sets default values
AEnemyPattern1::AEnemyPattern1()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshEnemy = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemy"));
	BulletSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpawnPoint"));
	BulletSpawnPoint->AttachToComponent(MeshEnemy, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AEnemyPattern1::BeginPlay()
{
	Super::BeginPlay();

	// spawn enemigo con el patron
	PatternEnemyB1 = GetWorld()->SpawnActor<AEnemyWithPattern>(AEnemyWithPattern::StaticClass());
	PatternEnemyB1->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AEnemyPattern1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyPattern1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// funciones

void AEnemyPattern1::builMeshEnemyB()
{
	if (!PatternEnemyB1) {
		UE_LOG(LogTemp, Error, TEXT("buildMeshBrick(): BrickEnemiga is NULL, asegurese de inicializar correctamente esta clase."));
		return;
	}

	PatternEnemyB1->setMeshBrickEnemy(MeshEnemy);
}

void AEnemyPattern1::builVelocityB()
{
	if (!PatternEnemyB1) {
		UE_LOG(LogTemp, Error, TEXT("buildVelocityBrick(): Enemiga is NULL, asegurese de inicializar correctamente esta clase."));
		return;
	}
	const float velocity = 100.0f;
	PatternEnemyB1->setVelocityBrick(velocity);
}

void AEnemyPattern1::buildBulletSpawnPoint()
{
	if (!PatternEnemyB1) {
		UE_LOG(LogTemp, Error, TEXT("buildMeshProjectile(): Enemiga is NULL, asegurese de inicializar correctamente esta clase."));
		return;
	}

	PatternEnemyB1->setBulletSpawnPoint(BulletSpawnPoint);
}

void AEnemyPattern1::buildDefenseSystem()
{
	if (!PatternEnemyB1) {
		UE_LOG(LogTemp, Error, TEXT("BuildSistemaDefensa(): Enemiga is NULL, asegurese de inicializar correctamente esta clase."));
		return;
	}
	PatternEnemyB1->setDefenseSystem("Sistema de defensa del enemigo ACTIVADO!!!");
}

void AEnemyPattern1::buildDisplacementSystem()
{
	if (!PatternEnemyB1) {
		UE_LOG(LogTemp, Error, TEXT("BuildSistemaDefensa(): Enemiga is NULL, asegurese de inicializar correctamente esta clase."));
		return;
	}
	PatternEnemyB1->setDisplacementSystem("Sistema de desplazamiento solo en eje horizontal.!");
}

AEnemyUIPatternBuilder* AEnemyPattern1::getEnemyBPattern()
{
	return nullptr;
	//return PatternEnemyB1;
}

