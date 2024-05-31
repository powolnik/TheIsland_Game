// RW&MH

#include "UI/Widget/Island_UserWidget.h"


void UIsland_UserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
