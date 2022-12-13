// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "MedKit.h"
#include "Brick.generated.h"

class UBoxComponent;

UCLASS()
class BRICKBREAKER00_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere, Category = "Componentes")
		UParticleSystem* ExplosionBrick; // para la explosion

	float SpeedModifierOnBounce = 1.0f;

	// destruccion del brick
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult);

	// direccion de la caja
	/*UFUNCTION()
		virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;*/


	void DestroyBrick();

	/*void CreateCapsule(FVector Location);*/

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*virtual AMedKit* CreateCapsule(FString NameCapsule, FVector Location) PURE_VIRTUAL(ABrick::CreateCapsule, return nullptr;);

	AMedKit* OrdenCapsule(FString Category, FVector Spawn);*/

};
