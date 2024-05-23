// RW&MH

using UnrealBuildTool;
using System.Collections.Generic;

public class TheIslandTarget : TargetRules
{
	public TheIslandTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "TheIsland" } );
	}
}
