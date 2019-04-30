// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "FocusAtPoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UFocusAtPoint : public UBTTaskNode
{
	GENERATED_BODY()
		EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	UPROPERTY(EditANywhere, Category = "Blackboard")
	struct FBlackboardKeySelector FocusPoint;
};
