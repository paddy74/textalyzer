message(STATUS "Preparing tests")

# Enable construction of test target
enable_testing()

# Create and link the test executables
add_executable(textalyzer.test_lowAnalyze src/test_lowAnalyze.cpp)
target_link_libraries(textalyzer.test_lowAnalyze textalyzer gcov)

add_executable(textalyzer.test_medAnalyze src/test_medAnalyze.cpp)
target_link_libraries(textalyzer.test_medAnalyze textalyzer gcov)

add_executable(textalyzer.test_highAnalyze src/test_highAnalyze.cpp)
target_link_libraries(textalyzer.test_highAnalyze textalyzer gcov)

add_executable(textalyzer.test_typedefs src/test_typedefs.cpp)
target_link_libraries(textalyzer.test_typedefs textalyzer gcov)

# Test definitions
macro(create_test target)
    add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro(create_test)

create_test(textalyzer.test_lowAnalyze)
create_test(textalyzer.test_medAnalyze)
create_test(textalyzer.test_highAnalyze)
create_test(textalyzer.test_typedefs)

message(STATUS "Preparing tests - done")
