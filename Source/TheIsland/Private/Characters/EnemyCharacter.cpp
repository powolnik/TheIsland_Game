// RW&MH

#include "Characters/EnemyCharacter.h"
#include "AbilitySystem/Island_AbilitySystemComponent.h"
#include "AbilitySystem/Island_AttributeSet.h"
#include "TheIsland/TheIsland.h"


AEnemyCharacter::AEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UIsland_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UIsland_AttributeSet>(TEXT("AttributeSet"));
}

void AEnemyCharacter::HighlightActor(bool bHighlight)
{
	if (bHighlight) //true
	{
		GetMesh()->SetRenderCustomDepth(true);
		GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
		return;
	}
	GetMesh()->SetRenderCustomDepth(false);
}
