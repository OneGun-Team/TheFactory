// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "AIController.h"
#include "FPSCharacter.h"



UBTTask_Attack::UBTTask_Attack()
{

}


EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    //캐릭터 변환
    //AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    AFPSCharacter* Character = Cast<AFPSCharacter>(OwnerComp.GetAIOwner()->GetPawn());

    if (Character == nullptr)
    {
        return EBTNodeResult::Failed;
    }

   // Character->Attack();

    return EBTNodeResult::Succeeded;
}
