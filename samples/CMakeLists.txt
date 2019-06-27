message(STATUS "Generating samples")

add_executable(textalyzer.example src/example.cpp)
target_link_libraries(textalyzer.example textalyzer)

message(STATUS "Generating samples - done")
