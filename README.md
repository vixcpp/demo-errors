# demo-errors

Intentional C++ compile-time and runtime errors used to test and improve Vix diagnostics.

This repository exists for contributors and developers who want to inspect, reproduce, and extend the error cases already handled by Vix.

## Why this repo exists

Vix aims to turn raw compiler and runtime failures into clearer, more actionable diagnostics.

To improve that system, we need a dedicated place with:

- intentional compile-time errors
- intentional runtime failures
- small isolated repro cases
- stable examples contributors can use when adding new error rules

This repository is that place.

## Who this is for

- contributors working on Vix diagnostics
- developers testing new friendly error rules
- maintainers validating current diagnostics
- anyone who wants to see how Vix handles real C++ failures

## Repository structure

```
template_error_rules_demo/
runtime_error_rules_demo/
```

#### `template_error_rules_demo/`

Small isolated template compilation errors used to validate friendly template diagnostics. Examples include:

- missing `typename` before dependent types
- missing nested types
- template argument mismatch
- substitution failure

#### `runtime_error_rules_demo/`

Small isolated runtime failures used to validate friendly runtime diagnostics. Examples include:

- joinable thread destruction
- data race
- deadlock
- mutex misuse
- condition variable misuse
- future/promise misuse
- thread creation failure
- detached thread lifetime bugs
- segmentation fault
- abort

## How to use this repo

Run the examples directly with Vix from the repository root:

```bash
vix run template_error_rules_demo/dependent_typename.cpp
vix run template_error_rules_demo/no_type_named.cpp
vix run runtime_error_rules_demo/thread_joinable.cpp --san
vix run runtime_error_rules_demo/data_race.cpp --san
vix run runtime_error_rules_demo/segfault.cpp --san
```

## Contribution goal

Each example in this repository should be:

- small
- intentional
- focused on one error family
- easy to run
- useful for validating a specific diagnostic rule

When adding a new example:

1. Keep it minimal
2. Make the failure intentional and obvious
3. Place it in the right demo folder
4. Document the expected Vix diagnostic

## Notes

- These files are intentionally broken.
- Some runtime demos are platform-dependent.
- Some runtime demos are more reliable with sanitizers enabled.
- These demos are for diagnostics work, not normal application usage.
