// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "Public/PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 WaypointIndex = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	AAIController* Controller = OwnerComp.GetAIOwner();
	APatrollingGuard* Character = Cast<APatrollingGuard>(Controller->GetPawn());
	TArray<AActor*> PatrolPoints = Character->GetPatrolPoints();

	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[WaypointIndex]);

	++WaypointIndex;
	if (WaypointIndex >= PatrolPoints.Num())
	{
		WaypointIndex -= PatrolPoints.Num();
	}

	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, WaypointIndex);

	return EBTNodeResult::Succeeded;
}

