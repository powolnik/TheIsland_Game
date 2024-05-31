// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Island_HUD.generated.h"

class UIsland_UserWidget;
class UIsland_OverlayWidgetController;
struct FWidgetControllerParameters;


UCLASS()
class THEISLAND_API AIsland_HUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UIsland_UserWidget> OverlayWidget;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UIsland_UserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UIsland_OverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UIsland_OverlayWidgetController> OverlayWidgetControllerClass;

public:
	UIsland_OverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParameters& WCParameters);
	void InitializeOverlay(APlayerController* PController, APlayerState* PState);
};
