cmake_minimum_required (VERSION 3.10.2)

# Set the project name to your project name, template isn't very descriptive
project (exercise-004 VERSION 0.0.1 LANGUAGES CXX)
string(TIMESTAMP BUILD_DATE "%Y-%m-%dT%H:%M:%S")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Include dependencies
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(Catch2 3 REQUIRED)

# use some fancy hack to provide a default input file for debugging
set(DEFAULT_BMP_FILE "${CMAKE_CURRENT_BINARY_DIR}/input.bmp")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/example/DHBW_24bit.bmp" ${DEFAULT_BMP_FILE} COPYONLY)

# create the config header which conveys CMake information to C++
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/include/config.h" @ONLY)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/include") # add the output path to the include PATH

# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# Add libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
                                        fmt::fmt
                                        CLI11::CLI11)