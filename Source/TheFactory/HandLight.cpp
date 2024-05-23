// Fill out your copyright notice in the Description page of Project Settings.


#include "HandLight.h"

// Sets default values
AHandLight::AHandLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHandLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHandLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

