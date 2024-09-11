// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TheFactoryController.generated.h"

/**
 * 
 */
UCLASS()
class THEFACTORY_API ATheFactoryController : public AAIController
{
	GENERATED_BODY()

public:



protected:
	virtual void BeginPlay() override;



private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

};
