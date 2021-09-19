// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardDrawController.h"
#include "Kismet/GameplayStatics.h"

ABoardDrawController::ABoardDrawController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	bIsDrawing = false;
}

void ABoardDrawController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bIsDrawing)
	{
		DrawAtMouseCursor();
	}
}

void ABoardDrawController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("Draw Here", IE_Pressed, this, &ABoardDrawController::OnMousePressed);
	InputComponent->BindAction("Draw Here", IE_Released, this, &ABoardDrawController::OnMouseReleased);
}

void ABoardDrawController::OnMousePressed()
{
	bIsDrawing = true;
}

void ABoardDrawController::OnMouseReleased()
{
	bIsDrawing = false;
}

void ABoardDrawController::DrawAtMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = true;
	QueryParams.bReturnFaceIndex = true;
	FVector WorldPosition;
	FVector WorldDirection;
	DeprojectMousePositionToWorld(WorldPosition, WorldDirection);
	GetWorld()->LineTraceSingleByChannel(Hit, WorldPosition, WorldPosition + WorldDirection * 10000, ECC_Visibility, QueryParams);
	//GetHitResultUnderCursor(ECC_Visibility, true, Hit);

	if (Hit.bBlockingHit)
	{
		FVector2D UV;
		UGameplayStatics::FindCollisionUV(Hit, 0, UV);
		// We hit something, move there
		SendDrawDataToBoard(UV);
	}
}