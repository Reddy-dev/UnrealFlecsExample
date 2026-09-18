// Copyright Epic Games, Inc. All Rights Reserved.

#include "FlecsExampleSystems.h"

#include "FlecsExample/Components/FlecsExampleComponents.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlecsExampleSystems)

void UFlecsExampleMovementSystem::BuildSystem(const TSolidNotNull<const UFlecsWorldInterfaceObject*> InWorld,
	TFlecsSystemBuilder<>& InBuilder) const
{
	InBuilder
		.Phase(EFlecsPhaseType::OnUpdate)
		.With<FFlecsExamplePosition&>() // 0
		.With<const FFlecsExampleVelocity>(); // 1
}

void UFlecsExampleMovementSystem::RunEachIterator(const TSolidNotNull<UFlecsWorldInterfaceObject*> InWorld,
	flecs::iter& InIterator)
{
	const double DeltaTime = InIterator.delta_time();
	
	const auto PositionField= InIterator.field<FFlecsExamplePosition>(0);
	const auto VelocityField = InIterator.field<const FFlecsExampleVelocity>(1);
	
	for (const FFlecsId EntityIndex : InIterator)
	{
		auto& [PositionValue] = PositionField[EntityIndex];
		const auto& [VelocityUnitsPerSecond] = VelocityField[EntityIndex];
		
		PositionValue += (VelocityUnitsPerSecond * DeltaTime);
	}
}

void UFlecsExampleManualHealthSystem::BuildSystem(const TSolidNotNull<const UFlecsWorldInterfaceObject*> InWorld,
	TFlecsSystemBuilder<>& InBuilder) const
{
	InBuilder
		.Phase(EFlecsPhaseType::PreUpdate)
		.With<FFlecsExampleManualHealth&>(); // 0
}

void UFlecsExampleManualHealthSystem::EachIterator(const TSolidNotNull<UFlecsWorldInterfaceObject*> InWorld,
	flecs::iter& InIterator, const FFlecsId InIndex)
{
	auto& [Current, Maximum] = InIterator.field_at<FFlecsExampleManualHealth>(0, InIndex);
	
	Maximum = FMath::Max(Maximum, 0.0f);
	Current = FMath::Clamp(Current, 0.0f, Maximum);
}
