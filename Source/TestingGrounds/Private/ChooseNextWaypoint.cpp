// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "Public/CharacterPatrol.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 WaypointIndex = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	AAIController* Controller = OwnerComp.GetAIOwner();
	UActorComponent* Component = Controller->GetPawn()->GetComponentByClass(UCharacterPatrol::StaticClass());
	UCharacterPatrol* CharacterPatrol = Cast<UCharacterPatrol>(Component);


	if (CharacterPatrol && CharacterPatrol->GetPatrolPoints().Num())
	{

		TArray<AActor*> PatrolPoints = CharacterPatrol->GetPatrolPoints();

		BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[WaypointIndex]);

		++WaypointIndex;
		WaypointIndex %= PatrolPoints.Num();

		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, WaypointIndex);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No component found or empty patrol list!"));
		return EBTNodeResult::Failed;
	}
	return EBTNodeResult::Succeeded;
}

