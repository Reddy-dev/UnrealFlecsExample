// Copyright Epic Games, Inc. All Rights Reserved.

#include "flecs.h"

#include "FlecsExample.h"

#include "Modules/ModuleManager.h"

#include "General/FlecsModuleRegistry.h"

void FFlecsExampleModule::StartupModule()
{
	UE::Flecs::FFlecsModuleRegistry::Get().RegisterUnrealFlecsModule("FlecsExample");
}

void FFlecsExampleModule::ShutdownModule()
{
	// @TODO: module unloading is currently unsupported
}

IMPLEMENT_PRIMARY_GAME_MODULE( FFlecsExampleModule, FlecsExample, "FlecsExample" );
