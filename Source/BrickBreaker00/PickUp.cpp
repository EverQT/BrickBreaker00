// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>
#include <Gameframework/RotatingMovementComponent.h>

#include "Paddle.h"

// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(FName("Collider"));

	SetRootComponent(Collider); //setear nuevo root(collider)

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());   //hijo del rootComponent

	RotateMovement = CreateDefaultSubobject<URotatingMovementComponent>(FName("RotateMove"));

}

void APickUp::NotifyActorBeginOverlap(AActor* OtherActor)
{
    // sobre escribir
    Super::NotifyActorBeginOverlap(OtherActor); // llama l a implementacion base

    // cast permite a los objetos poder comportarse como otros objetos 
    //que esten dentro de la misma familia
    Paddle = Cast<APaddle>(OtherActor);

    if (!Paddle) return; // no pudo tranformar a Actor termina la funcion
    
    // si no continua
    if (ActivatePickUp())
    {
        Destroy();
    }
}

bool APickUp::ActivatePickUp()
{
    return false;
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//const FVector MoveBrick = FVector(-1.0f, 0.f, 0.f); //direccion
	//const FVector Movement = MoveBrick * Velocity * DeltaTime; //Velocidad Brick

	//if (Movement.SizeSquared() > 0.0f) {
	//	const FRotator NewRotation = FRotator(0.0f, -9.0f, 0.0f);

	//	FHitResult Hit(1.0f);
	//	RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	//}

}

