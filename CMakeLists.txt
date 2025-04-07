cmake_minimum_required(VERSION 3.10)

# Project name
project(SimpleMediaMetadataParser)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main executable
add_executable(SimpleMediaMetadataParser main.cpp)

# Link stdc++fs only if you're on GCC < 9
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
        target_link_libraries(SimpleMediaMetadataParser stdc++fs)
    endif()
endif()
