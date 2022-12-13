


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BRICKBREAKER00_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	// metodo que aumenta la vida
	bool Heal(float amount);
	
	// metodo que disminuye la vida
	bool ToDamage(float amount);

public:
	// vida con la que inicia
	UPROPERTY(VisibleAnywhere, Category = Stats) float Life{ 100.0f };

private:
	// maximo de vida
	const float MAX_LIFE{ 100.0f };
		
};
