add_executable(textalyzer.test_main src/main.cpp)

target_link_libraries(textalyzer.test_main textalyzer)

enable_testing()
add_test(test_main textalyzer.test_main)
