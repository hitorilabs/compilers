# data-structures
toy implementations of data structures in C++

```
# for google benchmark (usually turn this off)
BENCHMARK_ENABLE_TESTING=ON

# this project
BUILD_BENCHMARKS=OFF 
BUILD_TESTS=OFF 

# for lsp
CMAKE_EXPORT_COMPILE_COMMANDS=ON
```

e.g. build with benchmarks on
```
cmake -DBUILD_BENCHMARKS=ON -DBENCHMARK_ENABLE_TESTING=OFF -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B build
```

---

It's [recommended](https://chromium.googlesource.com/external/github.com/pwnall/googletest/+/refs/tags/release-1.8.0/googletest/docs/FAQ.md#why-is-it-not-recommended-to-install-a-pre_compiled-copy-of-google-test-for-example_into-usr_local) that each project compiles Google Test itself

See [instructions](https://github.com/google/googletest/blob/main/googletest/README.md) for installing `googletest`

Typically you'll clone the `googletest` repo and run something like this:

```
cmake -DBUILD_GMOCK=OFF -B build 
sudo make -C build install
```
