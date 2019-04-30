// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterPatrol.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UCharacterPatrol : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterPatrol();

protected:
	UPROPERTY(EditAnywhere, Category = "Default")
	TArray<AActor*> PatrolPoints;

	UPROPERTY(EditAnywhere, Category = "Default")
	FVector FocusPoint;

	// Called when the game starts
	//virtual void BeginPlay() override;

	
public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TArray<AActor*> GetPatrolPoints() { return PatrolPoints; }

};
