// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

UCLASS()
class BRICKBREAKER00_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

	// Overlapping event indica cuando componente traslapo o intersecto otro objeto o se encuentra
	// dentro de otro actor, esto tambien se conoce como trigger
	void NotifyActorBeginOverlap(AActor* OtherActor) override;

	// modificar las hijas
	virtual bool ActivatePickUp();

protected:
	// componente de colision, que usaremos para detectar cuando un actor esta colisionando
	// o esta overlap con este objeto
	UPROPERTY(VisibleAnywhere, Category = Components)
		class UBoxComponent* Collider;

	// permitir renderizar este objeto en escena
	UPROPERTY(VisibleAnywhere, Category = Components)
		class UStaticMeshComponent* Mesh;

	// permitir rotacion
	UPROPERTY(VisibleAnywhere, Category = Components)
		class URotatingMovementComponent* RotateMovement;

	//hereden puedan utilizar igual la informacion del PickUp
	class APaddle* Paddle{ nullptr }; // los hijos puden ver la informacion y modificarla

	// nombre de la capsula
	FString CapsuleName;

	//void HitMesh(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
