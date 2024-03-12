﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RealtimeMeshComponent.h"
#include "GameFramework/Actor.h"
#include "RealtimeMeshDirect.generated.h"


/*
 *	This example is meant to show how to use the RMC without using the RealtimeMeshActor,
 *	and instead register a RealtimeMeshComponent yourself and work with it.
 */
UCLASS()
class REALTIMEMESHEXAMPLES_API ARealtimeMeshDirect : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<URealtimeMeshComponent> RealtimeMeshComponent;

	// Sets default values for this actor's properties
	ARealtimeMeshDirect();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
};
