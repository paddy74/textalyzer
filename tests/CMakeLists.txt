add_executable(textalyzer.test_lowAnalyze src/test_lowAnalyze.cpp)
target_link_libraries(textalyzer.test_lowAnalyze textalyzer)

add_executable(textalyzer.test_medAnalyze src/test_medAnalyze.cpp)
target_link_libraries(textalyzer.test_medAnalyze textalyzer)

add_executable(textalyzer.test_highAnalyze src/test_highAnalyze.cpp)
target_link_libraries(textalyzer.test_highAnalyze textalyzer)

enable_testing()
add_test(test_lowAnalyze textalyzer.test_lowAnalyze)
add_test(test_medAnalyze textalyzer.test_medAnalyze)
add_test(test_highAnalyze textalyzer.test_highAnalyze)
