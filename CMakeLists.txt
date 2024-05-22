cmake_minimum_required (VERSION 3.29)

project (tvdesktop
         VERSION 0.1.0
         LANGUAGES CXX
         DESCRIPTION "A proof-of-concept (POC) desktop environment"
         HOMEPAGE "https://github.com/tvisionde/tvdesktop")

file (GLOB_RECURSE SRCODE "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
add_executable (tvdesktop ${SRCODE})

configure_file (data/tvdesktop.desktop.in data/tvdesktop.desktop)

target_compile_features (tvdesktop PUBLIC cxx_std_17)
target_link_libraries (tvdesktop PUBLIC tvision)

install (TARGETS tvdesktop RUNTIME DESTINATION bin)