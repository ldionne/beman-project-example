## Testing a project

Tests are written using `lit`, the [LLVM Integrated Tester][]. Each test is an
independent executable with a `main` function. Tests are written in a pretty
basic way, using `assert`.

This approach allows these tests to be very portable, and in particular it makes
them compatible with the LLVM C++ Standard Library conformance test suite developed
as part of libc++, which is also reused by other implementations like the MSVC STL
and libstdc++.

### Writing tests

Tests are written as standalone executables with a `main` function. Tested conditions
are asserted using simple `assert(...)` statements. Various test flavors are supported:

- `.pass.cpp`
    These tests are built and run. The test succeeds if the program terminates normally
    with a `0` exit code. The test fails if it doesn't compile, link or if it exits with
    an error.
- `.verify.cpp`
    These tests run using `clang-verify`. This allows checking that specific diagnostics
    are being emitted at compile-time.

    Clang-verify supports various directives like `expected-error`, `expected-warning`, etc.
    The full set of directives supported and how to use them is documented in [the Clang
    documentation](https://clang.llvm.org/docs/InternalsManual.html#specifying-diagnostics).
- `.compile.pass.cpp`
    These tests don't run, they only compile. The test passes if the program compiles, and
    fails otherwise.
- `.sh.pass.cpp`
    These tests run whatever shell commands are specified in the `RUN` commands specified
    in the test. This provides a lot of flexibility for controlling how the test gets built
    and run, and can be used to check things that are otherwise difficult to test (e.g.
    compatibility between TUs built with different Standard modes).

### Running tests

To run all the tests in the project, use:

```shell
$ mkdir build
$ cmake -S . -B build -GNinja
$ ninja -C build check
```

You can run a single test in the project by using `lit` directly:

```shell
$ <build>/test/venv/bin/lit <build>/test/example-paper/test1.pass.cpp
```

That's not a typo, you must use the `<build>` directory as a prefix to the
path of the test you want to run. This lets `lit` find the testing configuration
that was generated by CMake.

[LLVM Integrated Tester]: https://llvm.org/docs/CommandGuide/lit.html
