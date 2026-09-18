// Copyright Epic Games, Inc. All Rights Reserved.

#include "Subsystems/FlecsExampleRegistrationSubsystem.h"

#include "Components/FlecsExampleComponents.h"
#include "Systems/FlecsExampleSystems.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlecsExampleRegistrationSubsystem)

void UFlecsExampleRegistrationSubsystem::OnFlecsWorldInitialized(const TSolidNotNull<UFlecsWorld*> InWorld)
{
	Super::OnFlecsWorldInitialized(InWorld);

	// Typed C++ registration API.
	InWorld->RegisterComponentType<FFlecsExampleManualCounter>();

	// Reflection registration API for a USTRUCT.
	InWorld->RegisterComponentType(FFlecsExampleManualHealth::StaticStruct());

	// Explicit UObject registration API. This class returns false from ShouldAutoRegisterFromCDO().
	InWorld->RegisterFlecsObject<UFlecsExampleManualHealthSystem>();
}
