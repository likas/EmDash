// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/EmDashAttributeSet.h"
#include "Net/UnrealNetwork.h"

UEmDashAttributeSet::UEmDashAttributeSet()
{
    InitHealth(100.f);
    InitMaxHealth(100.f);
    InitStamina(100.f);
    InitMaxStamina(100.f);
}

void UEmDashAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // Replicate attributes to everyone
    DOREPLIFETIME_CONDITION_NOTIFY(UEmDashAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UEmDashAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UEmDashAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UEmDashAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
}

// Health OnRep notifiers
void UEmDashAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEmDashAttributeSet, Health, OldValue);
}

void UEmDashAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEmDashAttributeSet, MaxHealth, OldValue);
}

//Stamina OnRep notifiers
void UEmDashAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEmDashAttributeSet, Stamina, OldValue);
}

void UEmDashAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEmDashAttributeSet, MaxStamina, OldValue);
}

void UEmDashAttributeSet::ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const
{
    if(Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
    }
    else if(Attribute == GetStaminaAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
    }
    else if(Attribute == GetMaxStaminaAttribute() || Attribute == GetMaxHealthAttribute())
    {
        NewValue = FMath::Max(NewValue, KINDA_SMALL_NUMBER); // Ensure max values are always positive
    }
}

void UEmDashAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // Clamp the new value to be within the min and max range
    ClampAttribute(Attribute, NewValue);
}

void UEmDashAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
    // Clamp the new base value to be within the min and max range
    ClampAttribute(Attribute, NewValue);
}