// RW&MH

#include "Characters/CharacterBase.h"


ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}


