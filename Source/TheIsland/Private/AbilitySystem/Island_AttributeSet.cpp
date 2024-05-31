// RW&MH

#include "AbilitySystem/Island_AttributeSet.h"
#include "AbilitySystem/Island_AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"


UIsland_AttributeSet::UIsland_AttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(100.f);
	InitMaxMana(100.f);
}

void UIsland_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION(UIsland_AttributeSet, Health, COND_None);
	DOREPLIFETIME_CONDITION(UIsland_AttributeSet, MaxHealth, COND_None);
	DOREPLIFETIME_CONDITION(UIsland_AttributeSet, Mana, COND_None);
	DOREPLIFETIME_CONDITION(UIsland_AttributeSet, MaxMana, COND_None);
}

#pragma region BaseAttributes_OnRep
	void UIsland_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UIsland_AttributeSet, Health, OldHealth);
	}

	void UIsland_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UIsland_AttributeSet, MaxHealth, OldMaxHealth);
	}

	void UIsland_AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UIsland_AttributeSet, Mana, OldMana);
	}

	void UIsland_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UIsland_AttributeSet, MaxMana, OldMaxMana);
	}
#pragma endregion BaseAttributes_OnRep