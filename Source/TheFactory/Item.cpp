// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	itemKey = -1;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::StartInteract()
{

}

void AItem::EndInteract()
{

}

void AItem::Destroy()
{
	K2_DestroyActor();
}
void AItem::Use()
{

}
void AItem::Picked()
{

}
void AItem::Put()
{

}

int AItem::GetItemKey() {
	return itemKey;
}

void AItem::SetItemKey(int inputItemKey) {
	itemKey = inputItemKey;
}