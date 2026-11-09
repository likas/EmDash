// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmDashGameMode.h"
#include "EmDashCharacter.h"
#include "EmDashPlayerController.h"
#include "EmDashPlayerState.h"

AEmDashGameMode::AEmDashGameMode()
{
	DefaultPawnClass = AEmDashCharacter::StaticClass();
	PlayerControllerClass = AEmDashPlayerController::StaticClass();
	PlayerStateClass = AEmDashPlayerState::StaticClass();
}