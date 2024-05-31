// RW&MH

#include "Characters/PlayerCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/Island_PlayerController.h"
#include "Player/Island_PlayerState.h"
#include "UI/HUD/Island_HUD.h"


APlayerCharacter::APlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	InitializeHUD();
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Init ability actor info for the server
	InitializeAbilityActorInfo();
	InitializeHUD();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	//Init ability actor info for the client
	InitializeAbilityActorInfo();
	InitializeHUD();
}

void APlayerCharacter::InitializeHUD()
{
	if (AIsland_PlayerController* PC = Cast<AIsland_PlayerController>(GetController()))
	{
		if (AIsland_HUD* HUD = Cast<AIsland_HUD>(PC->GetHUD()))
		{
			HUD->InitializeOverlay(PC, GetPlayerState());
		}
	}
}

void APlayerCharacter::InitializeAbilityActorInfo()
{
	AIsland_PlayerState* IslandPlayerState = Cast<AIsland_PlayerState>(GetPlayerState());
	check(IslandPlayerState);
	IslandPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(IslandPlayerState, this);
	AbilitySystemComponent = IslandPlayerState->GetAbilitySystemComponent();
	AttributeSet = IslandPlayerState->GetAttributeSet();
}
