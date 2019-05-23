message(STATUS "Preparing tests")

# Enable construction of test target
enable_testing()

# Create and link the test executables
add_executable(textalyzer.test_lowAnalyze src/test_lowAnalyze.cpp)
target_link_libraries(textalyzer.test_lowAnalyze textalyzer)

add_executable(textalyzer.test_medAnalyze src/test_medAnalyze.cpp)
target_link_libraries(textalyzer.test_medAnalyze textalyzer)

add_executable(textalyzer.test_highAnalyze src/test_highAnalyze.cpp)
target_link_libraries(textalyzer.test_highAnalyze textalyzer)

# Test definitions
macro(create_test target)
    add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro(create_test)

create_test(textalyzer.test_lowAnalyze)
create_test(textalyzer.test_medAnalyze)
create_test(textalyzer.test_highAnalyze)

message(STATUS "Preparing tests - done")

# -----------------------------------------------------------------------------
# Code Coverage report
# -----------------------------------------------------------------------------
# cmake .. -DENABLE_CODECOV=ON
# cmake --build .
# cmake --build target
if (ENABLE_CODECOV)
    set(COVERAGE_LCOV_EXCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/libs/*")
    include(CodeCoverage)

    APPEND_COVERAGE_COMPILER_FLAGS()

    SETUP_TARGET_FOR_COVERAGE_LCOV(
        NAME textalyzer.coverage_lowAnalyze
        EXECUTABLE $<TARGET_FILE:textalyzer.test_lowAnalyze>
        DEPENDENCIES textalyzer
    )

    SETUP_TARGET_FOR_COVERAGE_LCOV(
        NAME textalyzer.coverage_medAnalyze
        EXECUTABLE $<TARGET_FILE:textalyzer.test_medAnalyze>
        DEPENDENCIES textalyzer
    )

    SETUP_TARGET_FOR_COVERAGE_LCOV(
        NAME textalyzer.coverage_highAnalyze
        EXECUTABLE $<TARGET_FILE:textalyzer.test_highAnalyze>
        DEPENDENCIES textalyzer
    )
endif()
