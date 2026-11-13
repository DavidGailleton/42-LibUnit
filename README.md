# libunit

A small unit-test framework for C, written during a 42 Lyon weekend project (rush) with Erwann Lagouche ([airone01](https://github.com/airone01)).

## How it works

- Each test is a function `int test(void)` that returns 0 on success
- `load_test` adds a test to a list with a name and a timeout; `launch_tests` runs the list
- Every test runs in its own child process (`fork`), so a crash does not stop the run
- The report shows one line per test: `OK`, `KO`, or the signal that killed it (`SIGSEGV`, `SIGBUS`, `SIGABRT`, `SIGFPE`, `SIGPIPE`, `SIGKILL`), or a timeout
- `launch_tests` returns 0 only if every test passed

```c
int strlen_launcher(void)
{
    t_unit_test *tests = NULL;

    load_test(&tests, "basic", &basic_test, 5);
    load_test(&tests, "null", &null_test, 5);
    return (launch_tests(tests, "strlen"));
}
```

## Layout

| Folder | Content |
|---|---|
| `framework/` | The library (`libunit.a`) |
| `tests/` | Tests of the framework itself: one test per outcome (OK, KO, each signal, timeout) |
| `real_tests/` | Tests of real functions: `ft_strlen`, `ft_atoi`, `ft_strncmp`, `ft_strdup`, `ft_itoa` |
| `libft/` | My libft, used by the framework |

## Build and run

```sh
make          # builds libunit.a
make test     # builds and runs both test suites
```
