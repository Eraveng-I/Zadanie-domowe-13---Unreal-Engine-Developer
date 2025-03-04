// Fill out your copyright notice in the Description page of Project Settings.


#include "UBTT_CPP_Speed_Changer.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


UUBTT_CPP_Speed_Changer::UUBTT_CPP_Speed_Changer()
{
	//ustawini nazwy taska
	NodeName = "Change Movement Speed";

	speed = 200;
}

EBTNodeResult::Type UUBTT_CPP_Speed_Changer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	int KindOfAction = OwnerComp.GetBlackboardComponent()->GetValueAsInt(TEXT("OrderToGoAround"));

	// Pobranie AIController i Character
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController)
	{
		ACharacter* Character = Cast<ACharacter>(AIController->GetPawn());
		if (Character)
		{
			// Zmiana prêdkoœci
			if (KindOfAction == 0)
			{
				Character->GetCharacterMovement()->MaxWalkSpeed = 400;
			}
			
			if (KindOfAction == 1)
			{
				Character->GetCharacterMovement()->MaxWalkSpeed = 1200;
			}

			// Zwrócenie sukcesu
			return EBTNodeResult::Succeeded;
		}
	}

	// Zwrócenie porazki, jeœli nie znalziono postaci
	return EBTNodeResult::Failed;
}



