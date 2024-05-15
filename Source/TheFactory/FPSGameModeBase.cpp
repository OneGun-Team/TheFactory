// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameModeBase.h"
#include "FPSHUD.h"

AFPSGameModeBase::AFPSGameModeBase() : Super(){
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	HUDClass = AFPSHUD::StaticClass();
}