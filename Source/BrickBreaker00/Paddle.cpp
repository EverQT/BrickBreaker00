// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

#include "HealthComponent.h"
#include "SpeedComponent.h"
#include "Proyectil.h"

#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"


const FName APaddle::FireBinding("Fire");

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Paddle"));
	//RootComponent = SM_Paddle;

	SM_Paddle->SetEnableGravity(false);
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhysicActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Pawn Floating Movement"));

	Health = CreateDefaultSubobject<UHealthComponent>(FName("Health"));

	Damage = CreateDefaultSubobject<UHealthComponent>(FName("Damage"));

	SpeedPaddle = CreateDefaultSubobject<USpeedComponent>(FName("SpeedPaddle"));


	// Weapon
	GunOffset = FVector(0.f, 20.f, 0.f);
	FireRate = 0.1f;
	bCanFire = false;

	FireForwardValue = 0.0f;
	FireRightValue = 0.0f;

	FireUpValue = 1.0f;
	FireDownValue = 0.0f;
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();

	//AConcreteEnemy* ConcreteEnemy = GetWorld->SpawnActor<AConcreteEnemy>

}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &APaddle::Fire);

}

void APaddle::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 1.0f, false);
}

void APaddle::MoveVertical(float AxisValue)
{
	AddMovementInput(FVector(0.0f, 0.0f, 1.0f), AxisValue, false);

	FVector NewLocation = GetActorLocation();
}

void APaddle::Fire() {
	bCanFire = true;
	//UE_LOG(LogTemp, Warning, TEXT("Se presiono la tecla E "));
	// Create fire direction vector
	//UE_LOG(LogTemp, Warning, TEXT("FireForwardValue: %f FireRightValue: %f"), FireUpValue, FireDownValue, FireForwardValue, FireRightValue);
	/*const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);*/

	const FVector FireDirection = FVector(FireUpValue, FireDownValue, 1.f).GetClampedToMaxSize(1.0f);
	//const FVector FireDirection = FVector(0.f,1.f, 0.f).GetClampedToMaxSize(1.0f);
	//const FVector FireDirection = GetActorLocation();
	// Try and fire a shot
	FireShot(FireDirection);
}

void APaddle::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		const FRotator FireRotation = FireDirection.Rotation();
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
		}

		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &APaddle::ShotTimerExpired, FireRate);
		// try and play the sound if specified
	/*	if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}*/

		bCanFire = false;
		//}
	}
}

void APaddle::ShotTimerExpired()
{
	bCanFire = true;
}

