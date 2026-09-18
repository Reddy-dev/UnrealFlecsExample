@echo off
setlocal

set "PROJECT_ROOT=%~dp0"
set "SUBMODULE_PATH=%PROJECT_ROOT%Plugins\Unreal-Flecs"

if not exist "%SUBMODULE_PATH%\.git" (
	echo Unreal-Flecs is not initialized. Initializing submodules...
	git -C "%PROJECT_ROOT%" submodule update --init --recursive
	if errorlevel 1 goto :error
)

echo Updating Unreal-Flecs from origin/main...
git -C "%SUBMODULE_PATH%" pull --ff-only origin main
if errorlevel 1 goto :error

echo.
echo Unreal-Flecs is up to date.
echo To record a changed submodule revision, run:
echo   git add Plugins/Unreal-Flecs
echo   git commit -m "Update Unreal-Flecs submodule"
exit /b 0

:error
echo.
echo Failed to update Unreal-Flecs.
exit /b 1
