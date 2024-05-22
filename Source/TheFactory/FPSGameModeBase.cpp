// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameModeBase.h"


void AFPSGameModeBase::ChangeFPSWidget(int widgetMode) {
	if (currWidget != nullptr) {
		currWidget->RemoveFromViewport();
		currWidget = nullptr;
	}
	
	switch (widgetMode)
	{
	// play ȭ��
	case 0:
		nextWidget = playWidget;
		break;
	// inventory ȭ��
	case 1:
		nextWidget = inventoryWidget;
		break;
	default:
		break;
	}
	
	if (nextWidget != nullptr) {
		currWidget = CreateWidget<UUserWidget>(GetWorld(), nextWidget);
		if (currWidget != nullptr) {
			currWidget->AddToViewport();
		}
	}

}

void AFPSGameModeBase::BeginPlay() {
	Super::BeginPlay();
	ChangeFPSWidget(0);
}
