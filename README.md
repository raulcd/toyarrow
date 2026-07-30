# ToyArrow

ToyArrow is a toy Apache Arrow implementation on C++.

It is not meant to be production ready nor useful to anyone apart from someone willing to
improve their knowledge about the format.

### Building

CMake 3.25 or above is required.

Execute:
```bash
cmake -S . -B build
cmake --build build -v
```

Running tests:
```bash
ctest --test-dir build --output-on-failure
```
