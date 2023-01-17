// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickMovimiento.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"
#include "MovimientoComponent.h"

// Sets default values
ABrickMovimiento::ABrickMovimiento()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BrickMovimiento"));
	RootComponent = SM_Brick;

	//spawn 
	SM_Brick->SetSimulatePhysics(true);
	SM_Brick->SetEnableGravity(false);
	SM_Brick->SetConstraintMode(EDOFMode::XZPlane);
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision")); //detectar la colision
	Box_Collision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = Box_Collision;
	MovComp= CreateDefaultSubobject<UMovimientoComponent>(TEXT("Movimiento"));

}

void ABrickMovimiento::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{

	if (OtherActor->ActorHasTag("Ball")) {
		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrickMovimiento::DestroyBrickMovimiento, 0.1f, false);

	}
}

void ABrickMovimiento::DestroyBrickMovimiento()
{
	this->Destroy();
}

// Called when the game starts or when spawned
void ABrickMovimiento::BeginPlay()
{
	Super::BeginPlay();

	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABrickMovimiento::OnOverlapBegin);

	
}

// Called every frame
void ABrickMovimiento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

