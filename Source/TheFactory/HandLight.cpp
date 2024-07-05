// Fill out your copyright notice in the Description page of Project Settings.


#include "HandLight.h"
#include "Components/SpotLightComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AHandLight::AHandLight()
{	
	itemKey = 1;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collsion"));
	RootComponent = collision;
	
	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("HandLightSpotLight"));
	SpotLight->SetupAttachment(collision);
	
	
}

// Called when the game starts or when spawned
void AHandLight::BeginPlay()
{
	Super::BeginPlay();
	lightState = false;
	SpotLight->SetVisibility(false);
	
}

// Called every frame
void AHandLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHandLight::ToggleLight() {
	switch (lightState)
	{
	case true:
		lightState = false;
		break;
	case false:
		lightState = true;
		break;
	}

	SpotLight->SetVisibility(lightState);
}
