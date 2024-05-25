// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.h"
#include "HandLight.generated.h"

class USpotLightComponent;

UCLASS()
class THEFACTORY_API AHandLight : public AItem
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	USkeletalMeshComponent* HandLightMesh;
public:	
	// Sets default values for this actor's properties
	AHandLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleDefaultsOnly, Category = State)
	bool lightState;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = Light)
	USpotLightComponent* SpotLight;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ToggleLight();
};
