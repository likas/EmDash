// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "EmDashPlayerState.generated.h"

// FWD
class UEmDashAttributeSet;

UCLASS()
class EMDASH_API AEmDashPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	AEmDashPlayerState();
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* ASC;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UEmDashAttributeSet* EmdAttributeSet;

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return ASC;
	}


};
