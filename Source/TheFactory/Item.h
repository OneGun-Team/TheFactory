// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Item.generated.h"

UCLASS()
class THEFACTORY_API AItem : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Info")
	int itemKey;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Interactable 추상 메서드
	virtual void StartInteract() override;
	virtual void EndInteract() override;

	UFUNCTION()
	void Destroy();
	UFUNCTION()
	void Use();
	UFUNCTION()
	void Picked();
	UFUNCTION()
	void Put();
	UFUNCTION()
	int GetItemKey();
};
