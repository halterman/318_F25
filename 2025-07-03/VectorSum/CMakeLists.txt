cmake_minimum_required(VERSION 3.25.0)

#-----------------------------------------------------
# Edit project-specific information
#-----------------------------------------------------

set(EXECUTABLE prog)

#-----------------------------------------------------
# Usually leave the rest untouched
#-----------------------------------------------------

project(${EXECUTABLE} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Use stricter compiler warnings
if (MSVC)
    # Microsoft Visual C++
    add_compile_options(/EHsc /W4) 
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXECUTABLE}) 
else()
    # GCC and Clang
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

file(GLOB SRCS_LIST "*.cpp" "*.h")

add_executable(${EXECUTABLE} ${SRCS_LIST})
