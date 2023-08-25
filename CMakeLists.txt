cmake_minimum_required(VERSION 3.10)

# Define the project name and language
project(clirpg LANGUAGES CXX)

# Define the compiler options
set(CMAKE_CXX_STANDARD 20)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "-fcolor-diagnostics -fansi-escape-codes -g")
endif()

# Define the file directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(BIN_DIR ${CMAKE_BINARY_DIR}/bin)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

# Add the header inclusion directory
include_directories(${INC_DIR})

# Recursively find all .cpp files in SRC_DIR
file(GLOB_RECURSE SRCS ${SRC_DIR}/*.cpp)

# Define the executable name and source files
add_executable(${PROJECT_NAME} ${SRCS})

# Set the output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})