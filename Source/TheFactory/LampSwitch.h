// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LampSwitch.generated.h"


UCLASS()
class THEFACTORY_API ALampSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALampSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleDefaultsOnly, Category = State)
	bool lightState;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = Light)
	ULightComponent* cellingLight;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ToggleLight();
};
