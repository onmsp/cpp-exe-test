cmake_minimum_required(VERSION 3.20)
project(cpp_exe_test VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  # Static CRT so hello.exe runs without the VC++ redistributable.
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  add_compile_options(/W4 /permissive- /utf-8)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(calc STATIC src/calc.cpp)
target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(hello src/main.cpp)
target_link_libraries(hello PRIVATE calc)
target_compile_definitions(hello PRIVATE APP_VERSION="${PROJECT_VERSION}")

enable_testing()
add_executable(unit_tests tests/test_calc.cpp)
target_link_libraries(unit_tests PRIVATE calc)
add_test(NAME unit_tests COMMAND unit_tests)
add_test(NAME hello_runs COMMAND hello)
