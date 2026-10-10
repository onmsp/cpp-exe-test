# cpp-exe-test

A minimal C++17 test project that builds a Windows `hello.exe` with CMake + MSVC on GitHub Actions.

## Layout

```
CMakeLists.txt          build definition (calc lib, hello.exe, unit_tests.exe)
src/calc.h, calc.cpp    small library: add(), factorial()
src/main.cpp            hello.exe entry point
tests/test_calc.cpp     unit tests (standard library only, run via CTest)
.github/workflows/      ci.yml (build + test + artifact), release.yml (tag -> Release)
```

## Build locally (Windows, Visual Studio 2022 + CMake 3.20+)

```
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
build\Release\hello.exe
```

## Download the exe

- Every push / PR: the CI run uploads the `hello-windows-x64` artifact.
- Every `v*` tag: the Release workflow attaches `hello.exe` to the GitHub Release.

`hello.exe` is linked against the static MSVC runtime, so no VC++ redistributable is needed. It is not code-signed, so Windows SmartScreen may show a warning on first run.
