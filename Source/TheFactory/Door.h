// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Components/StaticMeshComponent.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class THEFACTORY_API ADoor : public AItem
{
	GENERATED_BODY()
private:
	float rotation = 0.0f;
	float OPEN_ROTATION = 90.0f;
	float CLOSE_ROTATION = 0.0f;

	bool isOpen = false;
	bool isDone = true;

protected:
	virtual void BeginPlay() override;
public:
	ADoor();
	virtual void Tick(float DeltaTime) override;
	virtual void StartInteract() override;
	UFUNCTION(BlueprintCallable, Category="getState")
	bool getOpenState() { return isOpen; };
	UFUNCTION(BlueprintCallable, Category = "getState")
	void setDoneState(bool state) { isDone = state; };
	UFUNCTION(BlueprintCallable, Category = "getState")
	bool getDoneState() { return isDone; };
};
