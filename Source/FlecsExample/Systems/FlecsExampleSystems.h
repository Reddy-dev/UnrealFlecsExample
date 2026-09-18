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
	virtual void RunEachIterator(const TSolidNotNull<UFlecsWorldInterfaceObject*> InWorld,
		flecs::iter& InIterator) override;

	virtual bool ShouldAutoRegisterFromCDO() const override
	{
		return true;
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

	/*
	 * Will auto default to EUnrealFlecsRegistrationScopeType::Unset which in this context, 
	 * because FlecsExamples unreal module is set to defualt to 
	 **/
	virtual EUnrealFlecsRegistrationScopeType GetRegistrationScopeType() const override
	{
		return EUnrealFlecsRegistrationScopeType::Module;
	}
}; // class UFlecsExampleManualHealthSystem
