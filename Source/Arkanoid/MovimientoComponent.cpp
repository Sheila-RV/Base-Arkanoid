// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoComponent.h"

// Sets default values for this component's properties
UMovimientoComponent::UMovimientoComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	

	// ...
}


// Called when the game starts
void UMovimientoComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	ladrillo = GetOwner();
}


// Called every frame
void UMovimientoComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (ladrillo->GetActorLocation().X == 120) {
		rever = -posiciones;
	}

	if (ladrillo->GetActorLocation().X == -120) {
		rever = posiciones;
	}

	ladrillo->AddActorLocalOffset(rever);
}




