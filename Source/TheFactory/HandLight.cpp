// Fill out your copyright notice in the Description page of Project Settings.


#include "HandLight.h"
#include "Components/SpotLightComponent.h"

// Sets default values
AHandLight::AHandLight()
{	
	itemKey = 1;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HandLightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HandLightMesh"));
	HandLightMesh->SetupAttachment(GetRootComponent());
	HandLightMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	HandLightMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("HandLightSpotLight"));
	SpotLight->SetupAttachment(HandLightMesh);
	
	
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

void AHandLight::ChangeCustomDepth(bool OnOff) {
	HandLightMesh->SetRenderCustomDepth(OnOff);
}
