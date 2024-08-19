// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "FPSCharacter.h"
#include "Components/SphereComponent.h"
#include "Chair.generated.h"

/**
 * 
 */
UCLASS()
class THEFACTORY_API AChair : public AItem
{
	GENERATED_BODY()

private:

protected:
	virtual void BeginPlay() override;
	AFPSCharacter* fpsCharacter;
	UPROPERTY(EditAnywhere, Category = Pos)
	USceneComponent* SitPos;
	UPROPERTY(EditAnywhere, Category = Pos)
	USceneComponent* StandPos;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = OverlapCollision)
	USphereComponent* OverlapCollision;
public:
	AChair();
	virtual void Tick(float DeltaTime) override;
	virtual void StartInteract() override;
};
