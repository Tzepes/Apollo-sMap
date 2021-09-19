// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomLocationsGenerator.h"

// Sets default values for this component's properties
URandomLocationsGenerator::URandomLocationsGenerator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void URandomLocationsGenerator::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

FVector URandomLocationsGenerator::RandomLocation(float Min, float Max)
{
	FVector Result;
	
	Result.X = FMath::FRandRange(Min, Max);
	Result.Y = FMath::FRandRange(Min, Max);
	Result.Z = FMath::FRandRange(Min, Max);
	
	return Result;
}

