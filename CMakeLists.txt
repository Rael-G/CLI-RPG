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
include_directories(${CMAKE_SOURCE_DIR}/external)

# Recursively find all .cpp files in SRC_DIR
file(GLOB_RECURSE SRCS ${SRC_DIR}/*.cpp)

# Define the executable name and source files
add_executable(${PROJECT_NAME} ${SRCS})

# Set the output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# From /res to /bin/data
set(RES_SOURCE_DIR "${CMAKE_SOURCE_DIR}/res")
set(DATA_DEST_DIR "${CMAKE_BINARY_DIR}/bin/data")
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${RES_SOURCE_DIR}
    ${DATA_DEST_DIR}
    COMMENT "Copying resources to output directory"
)