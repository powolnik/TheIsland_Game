// RW&MH

#include "Player/Island_PlayerState.h"
#include "AbilitySystem/Island_AbilitySystemComponent.h"
#include "AbilitySystem/Island_AttributeSet.h"


AIsland_PlayerState::AIsland_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UIsland_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UIsland_AttributeSet>(TEXT("AttributeSet"));
	
	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* AIsland_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
