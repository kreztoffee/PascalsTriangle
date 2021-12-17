cmake_minimum_required(VERSION 3.20)
project(PascalsTriangle VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG e2239ee6043f73722e7aa812a459f54a28552929 #release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker setti    ngs
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(PascalsTriangle)
set_target_properties(PascalsTriangle PROPERTIES DEBUG_POSTFIX _debug)
target_sources(PascalsTriangle PRIVATE
        main.cpp)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
target_compile_options(PascalsTriangle PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_include_directories(PascalsTriangle PRIVATE
        ${PROJECT_SOURCE_DIR}/include)

enable_testing()
add_executable(PascalsTriangleTest)
target_sources(PascalsTriangleTest PRIVATE
        test/main.cpp
        test/CoefficientCalculatorTest.cpp
        src/CoefficientCalculator.cpp)
target_include_directories(PascalsTriangleTest PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/test)
target_link_libraries(
        PascalsTriangleTest
        GTest::gtest
        GTest::gmock
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(PascalsTriangleTest)
