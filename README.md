[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Textalyzer

This is a C++ library to conduct multiple text analysis and preprocessing techniques.

## Getting started

Please read (FEATURES.md)[FEATURES.md] for details on how to utilize this library.

### Adding to your project

The recommended/intended way to add this library to you project is by including the following to your CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.13)
project(myProject)

include_directories("path/to/textalyzer/include")
add_subdirectory("path/to/textalyzer")

add_executable(myProject myProject_SOURCES)
# or `add_library(myProject myProject_SOURCES)`

target_link_libraries(myProject textalyzer)
```

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](tags).

## Authors

- **Patrick Cox** - [paddy74](https://github.com/paddy74)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
