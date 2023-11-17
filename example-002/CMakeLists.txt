cmake_minimum_required (VERSION 3.10.2)

# Set the project name to your project name, template isn't very descriptive
project (example-002 VERSION 0.0.1 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Include dependencies
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(Catch2 3 REQUIRED)


# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# Add libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
                                        fmt::fmt
)