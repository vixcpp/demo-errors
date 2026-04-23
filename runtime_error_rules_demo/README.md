# Runtime Error Rules Demo

This folder contains small intentional runtime failures used to demonstrate Vix friendly runtime diagnostics.

Each file focuses on one error family.

---

## Files

- `thread_joinable.cpp`
- `data_race.cpp`
- `deadlock.cpp`
- `mutex_misuse.cpp`
- `condvar_misuse.cpp`
- `future_broken_promise.cpp`
- `future_already_retrieved.cpp`
- `promise_already_satisfied.cpp`
- `thread_creation_failure.cpp`
- `detached_lifetime.cpp`
- `segfault.cpp`
- `abort.cpp`

---

## Run examples

```bash
vix run runtime_error_rules_demo/thread_joinable.cpp --san
vix run runtime_error_rules_demo/data_race.cpp --san
vix run runtime_error_rules_demo/deadlock.cpp
vix run runtime_error_rules_demo/mutex_misuse.cpp
vix run runtime_error_rules_demo/condvar_misuse.cpp
vix run runtime_error_rules_demo/future_broken_promise.cpp
vix run runtime_error_rules_demo/future_already_retrieved.cpp
vix run runtime_error_rules_demo/promise_already_satisfied.cpp
vix run runtime_error_rules_demo/thread_creation_failure.cpp
vix run runtime_error_rules_demo/detached_lifetime.cpp --san
vix run runtime_error_rules_demo/segfault.cpp --san
vix run runtime_error_rules_demo/abort.cpp
```

---

## Expected friendly rules

| File | Rule |
|------|------|
| `thread_joinable.cpp` | `ThreadJoinableRule` |
| `data_race.cpp` | `DataRaceRule` |
| `deadlock.cpp` | `DeadlockRule` |
| `mutex_misuse.cpp` | `MutexMisuseRule` |
| `condvar_misuse.cpp` | `ConditionVariableMisuseRule` |
| `future_broken_promise.cpp` | `FuturePromiseRule` |
| `future_already_retrieved.cpp` | `FuturePromiseRule` |
| `promise_already_satisfied.cpp` | `FuturePromiseRule` |
| `thread_creation_failure.cpp` | `ThreadCreationFailureRule` |
| `detached_lifetime.cpp` | `DetachedThreadLifetimeRule` |
| `segfault.cpp` | `SegfaultRule` |
| `abort.cpp` | `AbortRule` |

---

## Notes

- These files are intentionally broken.
- Some scenarios are platform-dependent.
- Some scenarios are more reliable with sanitizers enabled.
- These demos are for contributors and diagnostics testing, not CI.
