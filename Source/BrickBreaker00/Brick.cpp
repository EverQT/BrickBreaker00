// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Ball.h"


// Sets default values
ABrick::ABrick()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	static ConstructorHelpers::FObjectFinder<UParticleSystem> AssetExplosion(TEXT("ParticleSystem'/Game/Particles/P_Explosion.P_Explosion'"));
	ExplosionBrick = CreateDefaultSubobject<UParticleSystem>(TEXT("Explosion"));
	ExplosionBrick = AssetExplosion.Object;


	RootComponent = BoxCollision;

}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball")) {
		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);

		//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, GetActorTransform());

		/*FVector GetLocation = this->GetActorLocation();

		if (&ABrick::GetWorldTimerManager != false) {
			CreateCapsule(GetLocation);
		}*/
	}
}

void ABrick::DestroyBrick()
{
	this->Destroy();

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();


	// Velocidad de la nave
	//Velocity = 50.0f;

	// Vida de esta nave
	//Life = 20;

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
	//if (BoxCollision)
	//	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionBrick, GetActorTransform());

}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// Haciendo mover la nave enemiga
	//const FVector MoveDirection = FVector(-1.f, 0.f, 0.f);		// direccion del movimiento
	//const FVector Movement = MoveDirection * Velocity * DeltaTime;	// la velocidad en la que se va mover

	//if (Movement.SizeSquared() > 0.0f) {
	//	const FRotator NewRotation = FRotator(180.0f, 0.0f, 180.0f); // la rotacion de la nave enemiga

	//	FHitResult Hit(1.0f);
	//	RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	//}

	//// destruir la nave enemiga si sobrepasa el punto 850 en el eje de las X o si ya no tiene vida
	//if (this->GetActorLocation().X < -950.f || Life <= 0.f) {
	//	// efecto de la explosion
	//	if (Explosion)
	//		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ShipExplosionEnemy, GetActorTransform());


	//	this->Destroy();
	//}

}

//void ABrick::CreateCapsule(FVector Location)
//{
//
//	ABrick* CapsuleCreator = GetWorld()->SpawnActor<AHelpCapsules>(AHelpCapsules::StaticClass(), FVector(0.0f, 0.0f, -100.0f), FRotator::ZeroRotator);
//	ABasicCapsule* Capsule = CapsuleCreator->OrdenCapsule("Bomb", Location);
//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Capsula de %s"), *Capsule->GetCapsuleName()));
//
//}

//AMedKit* ABrick::OrdenCapsule(FString Category, FVector Spawn)
//{
//	AMedKit* Capsules = CreateCapsule(Category, Spawn);
//	return Capsules;
//}