// RW&MH


#include "Characters/EnemyCharacter.h"

#include "GeometryCollection/GeometryCollectionSimulationTypes.h"
#include "TheIsland/TheIsland.h"

AEnemyCharacter::AEnemyCharacter()
{
	// ...
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
