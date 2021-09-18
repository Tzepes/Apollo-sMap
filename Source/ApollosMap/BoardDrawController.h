// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BoardDrawController.generated.h"

/**
 * 
 */
UCLASS()
class APOLLOSMAP_API ABoardDrawController : public APlayerController
{
	GENERATED_BODY()

public:
	ABoardDrawController();

protected:
	bool bIsDrawing;

protected:
	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	void DrawAtMouseCursor();
	UFUNCTION(BlueprintImplementableEvent)
		void SendDrawDataToBoard(FVector2D UV);

	void OnMousePressed();
	void OnMouseReleased();
};
