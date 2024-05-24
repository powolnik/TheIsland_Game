#include "Player/TheIslandPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

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

void ATheIslandPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
}

void ATheIslandPlayerController::SetupInputSubsystem()
{
	InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(InputSubsystem);
	check(PlayerInputContext);
	InputSubsystem->AddMappingContext(PlayerInputContext, 0);
}

void ATheIslandPlayerController::SetupMouseCursorProperties()
{
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}