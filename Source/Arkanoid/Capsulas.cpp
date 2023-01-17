// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsulas.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"
#include "Paddle.h"


// Sets default values
ACapsulas::ACapsulas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Capsula = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Capsula"));
	RootComponent = SM_Capsula;

	
	SM_Capsula->SetEnableGravity(false);
	SM_Capsula->SetConstraintMode(EDOFMode::XZPlane);
	SM_Capsula->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Box_CollisionCapsula = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision Capsula")); //detectar la colision
	Box_CollisionCapsula->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = Box_CollisionCapsula;
	 
	//

	Movimiento = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Movimiento;


}

void ACapsulas::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{

	if (OtherActor->ActorHasTag("Paddle")) {
		
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ACapsulas::DestroyCapsula, 0.1f, false);

	}
}

void ACapsulas::DestroyCapsula()
{
	this->Destroy();
}

// Called when the game starts or when spawned
void ACapsulas::BeginPlay()
{
	Super::BeginPlay();
	Box_CollisionCapsula->OnComponentBeginOverlap.AddDynamic(this, &ACapsulas::OnOverlapBegin);


	//
	if (Target != nullptr) {
		StartLocation = GetActorLocation();
		Direccion = Target->GetActorLocation() - StartLocation;
		TotalDistancia = Direccion.Size();

		UE_LOG(LogTemp, Warning, TEXT("ACapsulas TotalDistancia =%f"), TotalDistancia);

		Direccion = Direccion.GetSafeNormal();
		ActualDistancia = 0.0f;

	}
	
}

// Called every frame
void ACapsulas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActualDistancia < TotalDistancia) {
		FVector Locacion = GetActorLocation();

		Locacion += Direccion * Speed * DeltaTime;

		SetActorLocation(Locacion);
		ActualDistancia = (Locacion - StartLocation).Size();

	}
	
}

