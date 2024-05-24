#include "Player/TheIslandPlayerController.h"
#include "EnhancedInputSubsystems.h"

ATheIslandPlayerController::ATheIslandPlayerController()
{
	bReplicates = true;
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ATheIslandPlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetupInputSubsystem();
	SetupMouseCursorProperties();
}

void ATheIslandPlayerController::SetupInputSubsystem()
{
	check(PlayerInputContext);

	InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(InputSubsystem);
	InputSubsystem->AddMappingContext(PlayerInputContext, 0);
}

void ATheIslandPlayerController::SetupMouseCursorProperties()
{
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}