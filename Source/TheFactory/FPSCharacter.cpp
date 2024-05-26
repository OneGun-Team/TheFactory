// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	
	PrimaryActorTick.bCanEverTick = true;
	isRun = false;
	hasHandlight = false;
	SitPos = FVector(-39.56f, 1.75f, 24.f);
	StandPos = FVector(-39.56f, 1.75f, 64.f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	MyMode = Cast<AFPSGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	defaultWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 앉기 자연스럽게 구현
	if (!cameraComponentPosChanged) {
		FVector currCameraPos = FirstPersonCameraComponent->GetRelativeLocation();
		switch (isSit)
		{
		case true:
			if (currCameraPos.Equals(SitPos)) {
				cameraComponentPosChanged = true;
				break;
			}
			FirstPersonCameraComponent->SetRelativeLocation(FMath::Lerp(currCameraPos, SitPos, 0.05f));
			break;
		case false:
			if (currCameraPos.Equals(StandPos)) {
				cameraComponentPosChanged = true;
				break;
			}
			FirstPersonCameraComponent->SetRelativeLocation(FMath::Lerp(currCameraPos, StandPos, 0.1f));
			break;
		}
	}
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AFPSCharacter::OnRun);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AFPSCharacter::OnWalk);
	PlayerInputComponent->BindAction("Sit", IE_Pressed, this, &AFPSCharacter::OnSit);
	PlayerInputComponent->BindAction("ToggleInventory", IE_Pressed, this, &AFPSCharacter::ToggleInventory);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFPSCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFPSCharacter::LookUpAtRate);
}

void AFPSCharacter::OnInteract() {

}

// 달리기 상태 변경 pressed left Shift
void AFPSCharacter::OnRun() {
	//UE_LOG(LogTemp, Log, TEXT("isRun is true"));
	isRun = true;
}

// 걷기 상태 변경 released left Shift
void AFPSCharacter::OnWalk() {
	//UE_LOG(LogTemp, Log, TEXT("isRun is false"));
	isRun = false;
}

// 앉기 상태/ 서있는 상태로 변경 pressed C 
void AFPSCharacter::OnSit() {
	isSit = !isSit;
	cameraComponentPosChanged = false;
	if (isSit) {
		//FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 24.f));
		walkForwardSpeed = 300.0f;
		runSpeed = 300.0f;
	}
	else {
		//FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
		walkForwardSpeed = 600.0f;
		runSpeed = 1200.0f;
	}
}

// 손전등 껐다 켰다를 위한 함수 for Blueprint
void AFPSCharacter::ToggleHandLight(AHandLight* HandLight) {
	HandLight->ToggleLight();
}

void AFPSCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		if (isRun) {
			GetCharacterMovement()->MaxWalkSpeed = runSpeed;
		}
		else {
			GetCharacterMovement()->MaxWalkSpeed = walkForwardSpeed;
		}
		// add movement in that direction
		UE_LOG(LogTemp, Log, TEXT("%f"), GetCharacterMovement()->MaxWalkSpeed);
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFPSCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		GetCharacterMovement()->MaxWalkSpeed = walkRightSpeed;
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFPSCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFPSCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// 인벤토리 껐다 켰다 하기
void AFPSCharacter::ToggleInventory() {
	widgetMode = widgetMode == 0 ? 1 : 0;
	MyMode->ChangeFPSWidget(widgetMode);
}
