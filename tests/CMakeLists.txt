message(STATUS "Generating tests")

# Create and link the test executables
add_executable(textalyzer.test_analyzer src/test_analyzer.cpp)
target_link_libraries(textalyzer.test_analyzer textalyzer)

# Test definitions
macro(create_test target)
    add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro(create_test)

create_test(textalyzer.test_analyzer)

message(STATUS "Generating tests - done")

# -----------------------------------------------------------------------------
# Code Coverage report
# -----------------------------------------------------------------------------
# cmake .. -DENABLE_CODECOV=ON
# cmake --build .
# cmake --target target
if (ENABLE_COVERAGE)
    include(CodeCoverage)
    set(COVERAGE_LCOV_EXCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/../libs/*")

    APPEND_COVERAGE_COMPILER_FLAGS()

    include(ProcessorCount)
    ProcessorCount(N_CORES)

    SETUP_TARGET_FOR_COVERAGE_LCOV(
        NAME textalyzer.coverage
        EXECUTABLE cd tests/ && ctest -j ${N_CORES}
        DEPENDENCIES
            testalyzer.test_analyzer
    )
endif()
