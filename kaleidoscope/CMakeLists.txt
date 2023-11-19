cmake_minimum_required(VERSION 3.14)
project(ads VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")

# Options to control building of benchmarks and tests
option(BUILD_BENCHMARKS "Build benchmarks" OFF)
option(BUILD_TESTS "Build tests" OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

# set(LIBRARY_SOURCES "${PROJECT_SOURCE_DIR}/src/smolcc.cpp")
# add_library(smolcc ${LIBRARY_SOURCES})
    

if(BUILD_BENCHMARKS OR BUILD_TESTS)
    include(FetchContent)

    # Benchmarks
    if(BUILD_BENCHMARKS)
        set(BENCHMARK_ENABLE_TESTING OFF)
        FetchContent_Declare(
            googlebenchmark
            GIT_REPOSITORY https://github.com/google/benchmark.git
            GIT_TAG v1.8.3
            )
        FetchContent_MakeAvailable(googlebenchmark)

        add_subdirectory(benchmarks)
    endif()

    # Tests
    if(BUILD_TESTS)
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.14.0
            )
        FetchContent_MakeAvailable(googletest)

        enable_testing()
        add_subdirectory(tests)
    endif()
endif()
