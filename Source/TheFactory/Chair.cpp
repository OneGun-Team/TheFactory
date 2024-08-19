// Fill out your copyright notice in the Description page of Project Settings.


#include "Chair.h"
#include "Kismet/GameplayStatics.h"


AChair::AChair() {
	//SitPos = CreateDefaultSubobject<USceneComponent>(TEXT("SitPos"));
	//SitPos->SetupAttachment(RootComponent);
	//StandPos = CreateDefaultSubobject<USceneComponent>(TEXT("StandPos"));
	//StandPos->SetupAttachment(RootComponent);
	OverlapCollision = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapCollision"));
	OverlapCollision->SetupAttachment(RootComponent);
	
}

void AChair::BeginPlay() {
	Super::BeginPlay();
	SitPos = Cast<USceneComponent>(GetDefaultSubobjectByName("Sit"));
	StandPos = Cast<USceneComponent>(GetDefaultSubobjectByName("Stand"));
	
}



void AChair::StartInteract() {
	fpsCharacter = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		
	if (fpsCharacter != nullptr) {
		fpsCharacter->CallTranslate(SitPos,StandPos, true);
	}
}
void AChair::Tick(float DeltaTime) {

}
