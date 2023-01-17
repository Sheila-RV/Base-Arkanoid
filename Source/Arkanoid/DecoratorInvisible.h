// Fill out your copyright notice in the Description page of Project Settings.
//DECORADOR MAIN

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BrickIndestructible.h"

#include "DecoratorInvisible.generated.h"




UCLASS()
class ARKANOID_API ADecoratorInvisible : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecoratorInvisible();
public:
	ABrickIndestructible* Ladrillo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
