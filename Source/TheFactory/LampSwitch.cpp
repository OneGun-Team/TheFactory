// Fill out your copyright notice in the Description page of Project Settings.


#include "LampSwitch.h"
#include "Components/LightComponent.h"

// Sets default values
ALampSwitch::ALampSwitch()
{	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALampSwitch::BeginPlay()
{
	Super::BeginPlay();
	lightState = false;
	cellingLight->SetVisibility(false);
}

// Called every frame
void ALampSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALampSwitch::ToggleLight() {
	switch (lightState)
	{
	case true:
		lightState = false;
		break;
	case false:
		lightState = true;
		break;
	}

	cellingLight->SetVisibility(lightState);
}

