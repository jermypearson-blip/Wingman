// All rights reserved by Picasso Rayne studios, 2025 all Unauthoried use is prohibited.

using UnrealBuildTool;
using System.Collections.Generic;

// 1. UBT requires the class name to match the file prefix followed by "Target"
public class WingmanServerTarget : TargetRules
{
    // 2. The constructor name must match the class name
    public WingmanServerTarget(TargetInfo Target) : base(Target)
    {
        // 3. Tells the compiler to build a headless dedicated server (no graphics, sound, or UI)
        Type = TargetType.Server;

        // Keeps compiler defaults aligned with current engine standards
        DefaultBuildSettings = BuildSettingsVersion.V5;

        // 4. Tells the build tool to compile your game's C++ code module into this server binary
        ExtraModuleNames.AddRange(new string[] { "Wingman" });
    }
}