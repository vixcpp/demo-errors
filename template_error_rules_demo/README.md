# Template Error Rules Demo

This folder contains small intentional template compilation errors used to demonstrate Vix friendly diagnostics.

Each file focuses on a single template error family.

---

## Files

- `dependent_typename.cpp`
- `no_type_named.cpp`
- `template_argument_mismatch.cpp`
- `substitution_failure.cpp`

---

## Run examples

```bash
vix run template_error_rules_demo/dependent_typename.cpp
vix run template_error_rules_demo/no_type_named.cpp
vix run template_error_rules_demo/template_argument_mismatch.cpp
vix run template_error_rules_demo/substitution_failure.cpp
```

---

## Expected friendly rules

| File | Rule |
|------|------|
| `dependent_typename.cpp` | `DependentTypenameRule` |
| `no_type_named.cpp` | `NoTypeNamedRule` |
| `template_argument_mismatch.cpp` | `TemplateArgumentMismatchRule` |
| `substitution_failure.cpp` | `SubstitutionFailureRule` |

---

## Notes

- These files are intentionally broken.
- They are meant for contributors and diagnostics testing.
- Exact raw compiler wording may vary between GCC and Clang.
