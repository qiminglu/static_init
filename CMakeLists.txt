project(STATIC_INIT LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# only build the shared lib
option(BUILD_SHARED_LIBS "Build shared libraries" TRUE)

# warnings
string(APPEND ${CMAKE_CXX_FLAGS} "-Wall -Werror")

# python
add_subdirectory(pybind11)


add_library(synergia_core SHARED syn_core.cc)

add_library(lsexpr SHARED lsexpr.cc)
target_link_libraries(lsexpr synergia_core)

pybind11_add_module(pylsexpr lsexpr_pywrap.cc)
target_link_libraries(pylsexpr PRIVATE lsexpr)


add_executable(cxx_load cxx_load.cc)
target_link_libraries(cxx_load synergia_core)
