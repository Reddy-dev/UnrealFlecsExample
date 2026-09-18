// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Systems/FlecsSystemObject.h"

#include "FlecsExampleSystems.generated.h"

/** Auto-discovered object-registration example. */
UCLASS()
class FLECSEXAMPLE_API UFlecsExampleMovementSystem final : public UFlecsSystemObject
{
	GENERATED_BODY()

public:
	virtual void BuildSystem(const TSolidNotNull<const UFlecsWorldInterfaceObject*> InWorld,
		TFlecsSystemBuilder<>& InBuilder) const override;
	virtual void EachIterator(const TSolidNotNull<UFlecsWorldInterfaceObject*> InWorld,
		flecs::iter& InIterator, const FFlecsId InIndex) override;

	virtual bool ShouldAutoRegisterFromCDO() const override
	{
		return true;
	}

	virtual EUnrealFlecsRegistrationScopeType GetRegistrationScopeType() const override
	{
		return EUnrealFlecsRegistrationScopeType::Module;
	}
}; // class UFlecsExampleMovementSystem

/** Explicit object-registration example, registered by UFlecsExampleRegistrationSubsystem. */
UCLASS()
class FLECSEXAMPLE_API UFlecsExampleManualHealthSystem final : public UFlecsSystemObject
{
	GENERATED_BODY()

public:
	virtual void BuildSystem(const TSolidNotNull<const UFlecsWorldInterfaceObject*> InWorld,
		TFlecsSystemBuilder<>& InBuilder) const override;
	virtual void EachIterator(const TSolidNotNull<UFlecsWorldInterfaceObject*> InWorld,
		flecs::iter& InIterator, const FFlecsId InIndex) override;

	virtual bool ShouldAutoRegisterFromCDO() const override
	{
		return false;
	}

	virtual EUnrealFlecsRegistrationScopeType GetRegistrationScopeType() const override
	{
		return EUnrealFlecsRegistrationScopeType::Module;
	}
}; // class UFlecsExampleManualHealthSystem
