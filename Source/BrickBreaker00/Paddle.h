// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"

class UFloatingPawnMovement;

UCLASS()
class BRICKBREAKER00_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Paddle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;

	UPROPERTY(VisibleAnywhere, Category = Components)
		class UHealthComponent* Health;

	UPROPERTY(VisibleAnywhere, Category = Components)
		class UHealthComponent* Damage;

	UPROPERTY(VisibleAnywhere, Category = Components)
		class USpeedComponent* SpeedPaddle;



public:
	//metodo accesor
	FORCEINLINE class UHealthComponent* GetHealthComponent() const{ return Health; };

	//metodo accesor
	FORCEINLINE class USpeedComponent* GetSpeedComponent() const { return SpeedPaddle; };
	
	//metodo accesor
	//FORCEINLINE class UHealthComponent* GetHealthComponent()  { return Damage; };

	static const FName FireBinding;

public:
	void Fire();

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

private:
	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	// dispara a los lados
	float FireForwardValue;
	float FireRightValue;

	//dispara al frente
	float FireUpValue;
	float FireDownValue;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Metodos Movimiento Paddle 
	virtual void MoveHorizontal(float AxisValue);
	virtual void MoveVertical(float AxisValue);

};
