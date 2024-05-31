// RW&MH

#include "UI/WidgetController/Island_WidgetController.h"


void UIsland_WidgetController::SetWidgetControllerParameters(const FWidgetControllerParameters& WCParameters)
{
	PlayerController = WCParameters.PlayerController;
	PlayerState = WCParameters.PlayerState;
}
