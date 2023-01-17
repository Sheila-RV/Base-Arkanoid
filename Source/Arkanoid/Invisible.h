// Fill out your copyright notice in the Description page of Project Settings.
//DECORADOR 1 : INVISIBLE
#pragma once

#include "CoreMinimal.h"
#include "DecoratorInvisible.h"
#include "Invisible.generated.h"

/**
 * 
 */
//class UMaterialInstanceDynamic:

UCLASS()
class ARKANOID_API AInvisible : public ADecoratorInvisible
{
	GENERATED_BODY()


		void agregarMesh(ABrickIndestructible ladrillo);

//private:
	//UMaterialInstanceDynamic* Materialdinamico;


	
};
