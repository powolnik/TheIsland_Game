// RW&MH

using UnrealBuildTool;
using System.Collections.Generic;

public class TheIslandEditorTarget : TargetRules
{
	public TheIslandEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "TheIsland" } );
	}
}
