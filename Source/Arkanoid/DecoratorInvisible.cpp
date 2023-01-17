// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoratorInvisible.h"

#include "Invisible.h"

// Sets default values
ADecoratorInvisible::ADecoratorInvisible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecoratorInvisible::BeginPlay()
{
	Super::BeginPlay();

	AInvisible* invi = GetWorld() -> SpawnActor<AInvisible>(AInvisible::StaticClass());
	//invi->agregarMesh(Ladrillo);

	//Ladrillo = invi;


}

// Called every frame
void ADecoratorInvisible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

