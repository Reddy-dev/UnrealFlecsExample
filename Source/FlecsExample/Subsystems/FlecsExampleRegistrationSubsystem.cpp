// Copyright Epic Games, Inc. All Rights Reserved.

#include "FlecsExampleRegistrationSubsystem.h"

#include "FlecsExample/Components/FlecsExampleComponents.h"
#include "FlecsExample/Systems/FlecsExampleSystems.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlecsExampleRegistrationSubsystem)

void UFlecsExampleRegistrationSubsystem::OnFlecsWorldInitialized(const TSolidNotNull<UFlecsWorld*> InWorld)
{
	Super::OnFlecsWorldInitialized(InWorld);

	// Typed C++ registration API.
	InWorld->RegisterComponentType<FFlecsExampleManualCounter>();

	// Reflection registration API for a USTRUCT. (can be called in blueprints)
	InWorld->RegisterComponentType(FFlecsExampleManualHealth::StaticStruct());

	// Explicit UObject registration API. This class returns false from ShouldAutoRegisterFromCDO().
	InWorld->RegisterFlecsObject<UFlecsExampleManualHealthSystem>();
	
	InWorld->CreateEntity(TEXT("Example_MovingForward"))
		.Set<FFlecsExampleDisplayName>({ .Value = TEXT("Forward Mover") })
		.Set<FFlecsExamplePosition>({ .Value = FVector::ZeroVector })
		.Set<FFlecsExampleVelocity>({ .UnitsPerSecond = FVector(100.0, 0.0, 0.0) });

	InWorld->CreateEntity(TEXT("Example_MovingDiagonal"))
		.Set<FFlecsExampleDisplayName>({ .Value = TEXT("Diagonal Mover") })
		.Set<FFlecsExamplePosition>({ .Value = FVector(0.0, 200.0, 0.0) })
		.Set<FFlecsExampleVelocity>({ .UnitsPerSecond = FVector(50.0, -50.0, 0.0) });

	// The manual health system clamps Current from 150 to Maximum on its next PreUpdate.
	InWorld->CreateEntity(TEXT("Example_Overhealed"))
		.Set<FFlecsExampleDisplayName>({ .Value = TEXT("Overhealed Entity") })
		.Set<FFlecsExampleManualHealth>({ .Current = 150.0f, .Maximum = 100.0f })
		.Set<FFlecsExampleManualCounter>({ .Value = 1 });

	// This entity has no velocity, demonstrating that the movement system only matches both query fields.
	InWorld->CreateEntity(TEXT("Example_Stationary"))
		.Set<FFlecsExampleDisplayName>({ .Value = TEXT("Stationary Entity") })
		.Set<FFlecsExamplePosition>({ .Value = FVector(0.0, -200.0, 0.0) });
}
