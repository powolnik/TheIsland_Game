// RW&MH


#include "Characters/TheIslandEnemy.h"
#include "TheIsland/TheIsland.h"

ATheIslandEnemy::ATheIslandEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetMesh()->SetCollisionObjectType(ECC_Pawn);
}

void ATheIslandEnemy::HighlightActor(bool bHighlight)
{
	if (bHighlight) //true
	{
		GetMesh()->SetRenderCustomDepth(true);
		GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
		return;
	}
	GetMesh()->SetRenderCustomDepth(false);
}
