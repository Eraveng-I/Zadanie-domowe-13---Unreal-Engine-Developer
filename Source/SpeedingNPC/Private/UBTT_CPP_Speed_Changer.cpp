// Fill out your copyright notice in the Description page of Project Settings.


#include "UBTT_CPP_Speed_Changer.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"


UUBTT_CPP_Speed_Changer::UUBTT_CPP_Speed_Changer()
{
	//ustawini nazwy taska
	NodeName = "Change Movement Speed";

	speed = 200;

	
}

EBTNodeResult::Type UUBTT_CPP_Speed_Changer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//int* KindOfAction = Cast<int>(OwnerComp.GetBlackboardComponent()->GetV)
	//int* KindOfAction = OwnerComp.GetBlackboardComponent()->execGetValueAsInt(OrderToGoAround.SelectedKeyName);
	int* KindOfAction = Cast <int>( OwnerComp.GetBlackboardComponent()->GetValueAsInt(OrderToGoAround.SelectedKeyName));

	return EBTNodeResult::Type();
}



