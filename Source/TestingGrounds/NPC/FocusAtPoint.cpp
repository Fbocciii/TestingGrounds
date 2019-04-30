// Fill out your copyright notice in the Description page of Project Settings.

#include "FocusAtPoint.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CharacterPatrol.h"

EBTNodeResult::Type UFocusAtPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	FVector FocusVector = BlackboardComp->GetValueAsVector(FocusPoint.SelectedKeyName);

	AAIController* Controller = OwnerComp.GetAIOwner();

	Controller->SetFocalPoint(FocusVector);

	//UActorComponent* Component = Controller->GetPawn()->GetComponentByClass(UCharacterPatrol::StaticClass());
	//UCharacterPatrol* CharacterPatrol = Cast<UCharacterPatrol>(Component);


	return EBTNodeResult::Succeeded;
}
