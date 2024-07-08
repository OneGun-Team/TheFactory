// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

ADoor::ADoor() {

}

void ADoor::BeginPlay() {
	Super::BeginPlay();
}

void ADoor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ADoor::StartInteract() {
	if (isDone) {
		//UE_LOG(LogTemp, Log, TEXT("%d"), isOpen);
		isOpen = !isOpen;
		isDone = false;
	}
}

