@echo off
:: Check if the script is run as administrator
net session >nul 2>&1
if %errorlevel% neq 0 (
    echo This script needs to be run as administrator.
    echo Please right-click on the batch file and select 'Run as administrator'.
    pause
    exit /b
)

:: Start Visual Studio 2022 as administrator
echo Starting Visual Studio 2022 as Administrator...
powershell -Command "Start-Process 'C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe' -ArgumentList 'U:\UE5\Proj\TheIsland\TheIsland.sln' -Verb runAs"

:: Wait for the specific Visual Studio window to appear
echo Waiting for Visual Studio to load the solution...
:waitLoop
timeout /t 12 

:: Start Unreal Editor with the project
echo Starting Unreal Editor...
start "" "C:\DEV\UEngines\UE_5.4\Engine\Binaries\Win64\UnrealEditor.exe" "U:\UE5\Proj\TheIsland\TheIsland.uproject"

:: Optional: Keep the command prompt open to see any error messages
exit
