// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Capsulas.generated.h"

class UBoxComponent;
UCLASS()
class ARKANOID_API ACapsulas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACapsulas();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Capsula;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* Box_CollisionCapsula;
	float SpeedModifierOnBounce = 1.01f;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult);

	void DestroyCapsula();


	//

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "MoveActor")
		class USceneComponent* Movimiento;

	UPROPERTY(EditAnywhere, Category = "MoveActor")
		class AActor* Target;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//
	UPROPERTY(EditAnywhere, Category = "MoveActor")
		float Speed;
	FVector Direccion;

	float TotalDistancia;
	float ActualDistancia;
	FVector StartLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
