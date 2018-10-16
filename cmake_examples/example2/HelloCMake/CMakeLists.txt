cmake_minimum_required( VERSION 3.2 )

project (CMakeHelloWorld)

find_package(Boost COMPONENTS system)

add_subdirectory(src_dir)

add_subdirectory(lib_dir)

