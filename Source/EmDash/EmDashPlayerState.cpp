// Fill out your copyright notice in the Description page of Project Settings.


#include "EmDashPlayerState.h"
#include "AbilitySystemComponent.h"
#include "EmDashAttributeSet.h"

AEmDashPlayerState::AEmDashPlayerState()
{
    ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    EmdAttributeSet = CreateDefaultSubobject<UEmDashAttributeSet>(TEXT("EmDashAttributeSet"));
}

void AEmDashPlayerState::BeginPlay()
{
    Super::BeginPlay();

    ASC->SetIsReplicated(true);
    ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    // Raise default net update frequency for GAS to work better
	SetNetUpdateFrequency(100.f);
}