// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FlecsExampleComponents.h"

REGISTER_FLECS_COMPONENT(FFlecsExamplePosition);
REGISTER_FLECS_COMPONENT(FFlecsExampleVelocity);
REGISTER_FLECS_COMPONENT(FFlecsExamplePersistentTrait);
REGISTER_FLECS_COMPONENT(FFlecsExampleDisplayName);

// These publish type metadata, but AutoRegister = false keeps registration world-local and explicit.
REGISTER_FLECS_COMPONENT(FFlecsExampleManualHealth);
REGISTER_FLECS_COMPONENT(FFlecsExampleManualCounter);
