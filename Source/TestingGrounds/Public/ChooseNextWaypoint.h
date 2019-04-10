// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "ChooseNextWaypoint.generated.h"


/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
		EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditANywhere, Category = "Blackboard")
	struct FBlackboardKeySelector Index;
};
