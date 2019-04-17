add_executable(MainTest src/main.cpp)

target_link_libraries(MainTest textalyzer)

enable_testing()
add_test(test_main MainTest)
