# UnrealFlecsExample

Small project-level Unreal-Flecs examples live under `Source/FlecsExample`:

- `Components/FlecsExampleComponents.*` shows reflected and native C++ components, the `DontFragment` component option, a custom trait, automatic type registration, and manual-only types.
- `Systems/FlecsExampleSystems.*` shows an automatically discovered `UFlecsSystemObject` and an object which opts into explicit registration.
- `Subsystems/FlecsExampleRegistrationSubsystem.*` derives from `UFlecsAbstractWorldSubsystem`, owns all per-world manual component and object registration, and creates the example entities when the Flecs world is initialized.

The movement system uses the normal iterator-field API (`With`, `EachIterator`, and `field_at`). Add `FFlecsExamplePosition` and `FFlecsExampleVelocity` to an entity to make it move during `OnUpdate`.

The registration subsystem creates four named examples:

- `Example_MovingForward` and `Example_MovingDiagonal` have position and velocity components, so the movement system updates them every frame.
- `Example_Overhealed` starts with `Current = 150` and `Maximum = 100`; the explicitly registered health system clamps it to its maximum during `PreUpdate`.
- `Example_Stationary` has a position but no velocity, demonstrating that it does not match the movement query.
