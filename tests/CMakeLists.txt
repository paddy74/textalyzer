message(STATUS "Preparing tests")

# Enable construction of test target
enable_testing()

# Create and link the test executables
add_executable(textalyzer.test_analyzer src/test_analyzer.cpp)
target_link_libraries(textalyzer.test_analyzer textalyzer)

# Test definitions
macro(create_test target)
    add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro(create_test)

create_test(textalyzer.test_analyzer)

message(STATUS "Preparing tests - done")
