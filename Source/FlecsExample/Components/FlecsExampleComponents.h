// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Properties/FlecsComponentProperties.h"

#include "FlecsExampleComponents.generated.h"

/** A normal reflected component. REGISTER_FLECS_COMPONENT auto-registers it with each Flecs world. */
USTRUCT(BlueprintType)
struct FLECSEXAMPLE_API FFlecsExamplePosition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flecs Example")
	FVector Value = FVector::ZeroVector;
}; // struct FFlecsExamplePosition

/** A normal reflected component with a built-in Flecs trait. */
USTRUCT(BlueprintType)
struct FLECSEXAMPLE_API FFlecsExampleVelocity
{
	GENERATED_BODY()
	
	static constexpr bool DontFragment = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flecs Example")
	FVector UnitsPerSecond = FVector::ZeroVector;
}; // struct FFlecsExampleVelocity

template <>
struct TFlecsComponentTraits<FFlecsExampleVelocity> : public TFlecsComponentTraitsBase<FFlecsExampleVelocity>
{
	// Enables or disables this component per entity without moving the entity to a different table.
	static constexpr bool DontFragment = true;
}; // struct TFlecsComponentTraits<FFlecsExampleVelocity>

/** A custom trait component which can be attached to other component definitions. */
USTRUCT()
struct FLECSEXAMPLE_API FFlecsExamplePersistentTrait
{
	GENERATED_BODY()
}; // struct FFlecsExamplePersistentTrait

template <>
struct TFlecsComponentTraits<FFlecsExamplePersistentTrait> : public TFlecsComponentTraitsBase<FFlecsExamplePersistentTrait>
{
	static constexpr bool Trait = true;
}; // struct TFlecsComponentTraits<FFlecsExamplePersistentTrait>

/** This component definition receives FFlecsExamplePersistentTrait during registration. */
USTRUCT(BlueprintType)
struct FLECSEXAMPLE_API FFlecsExampleDisplayName
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flecs Example")
	FString Value;
}; // struct FFlecsExampleDisplayName

template <>
struct TFlecsComponentTraits<FFlecsExampleDisplayName> : public TFlecsComponentTraitsBase<FFlecsExampleDisplayName>
{
	using CustomTraits = TTuple<FFlecsExamplePersistentTrait>;
}; // struct TFlecsComponentTraits<FFlecsExampleDisplayName>

/** Registered per world through UFlecsExampleRegistrationSubsystem's reflected-type API example. */
USTRUCT(BlueprintType)
struct FLECSEXAMPLE_API FFlecsExampleManualHealth
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flecs Example", meta = (ClampMin = "0.0"))
	float Current = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flecs Example", meta = (ClampMin = "0.0"))
	float Maximum = 100.0f;
}; // struct FFlecsExampleManualHealth

// alternative way of writing out the traits
FLECS_COMPONENT_TRAITS(FFlecsExampleManualHealth)
{
	static constexpr bool AutoRegister = false;
}; // struct TFlecsComponentTraits<FFlecsExampleManualHealth>

/** A non-reflected C++ component registered through the subsystem's typed API example. */
struct FLECSEXAMPLE_API FFlecsExampleManualCounter
{
	int32 Value = 0;
}; // struct FFlecsExampleManualCounter

template <>
struct TFlecsComponentTraits<FFlecsExampleManualCounter> : public TFlecsComponentTraitsBase<FFlecsExampleManualCounter>
{
	static constexpr bool AutoRegister = false;
}; // struct TFlecsComponentTraits<FFlecsExampleManualCounter>
