// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Worlds/FlecsAbstractWorldSubsystem.h"

#include "FlecsExampleRegistrationSubsystem.generated.h"

/** Owns every example that intentionally opts out of automatic world registration. */
UCLASS()
class FLECSEXAMPLE_API UFlecsExampleRegistrationSubsystem final : public UFlecsAbstractWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void OnFlecsWorldInitialized(const TSolidNotNull<UFlecsWorld*> InWorld) override;
}; // class UFlecsExampleRegistrationSubsystem
