// RW&MH

#include "UI/HUD/Island_HUD.h"
#include "UI/Widget/Island_UserWidget.h"
#include "UI/WidgetController/Island_OverlayWidgetController.h"


UIsland_OverlayWidgetController* AIsland_HUD::GetOverlayWidgetController(const FWidgetControllerParameters& WCParameters)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UIsland_OverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParameters(WCParameters);

		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AIsland_HUD::InitializeOverlay(APlayerController* PController, APlayerState* PState)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class not set! Fill Out BP_Island_HUD!"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class not set! Fill Out BP_Island_HUD!"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UIsland_UserWidget>(Widget);

	const FWidgetControllerParameters WidgetControllerParameters(PController, PState);
	UIsland_OverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParameters);

	OverlayWidget->SetWidgetController(WidgetController);
	
	Widget->AddToViewport();
}


