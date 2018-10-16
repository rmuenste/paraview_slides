cmake_minimum_required( VERSION 3.2 )

project (CMakeHelloWorld_WithExternalProject)

include(ExternalProject)

ExternalProject_Add(HELLO_PRJ
  GIT_REPOSITORY https://github.com/rmuenste/FamousHelloLibrary.git 
  GIT_TAG master
  SOURCE_DIR ${CMAKE_BINARY_DIR}/FamousHelloLib
  PREFIX ${CMAKE_BINARY_DIR}/FamousHelloLib-dir
  CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/FamousHelloLib-install -DBUILD_SHARED_LIBS=False
  )

set (MAIN_SOURCE helloworld.cpp)

add_executable(hello_world ${MAIN_SOURCE})

add_dependencies(hello_world HELLO_PRJ)

target_compile_definitions(hello_world PRIVATE BAR=1)
target_include_directories(hello_world PRIVATE ${CMAKE_BINARY_DIR}/FamousHelloLib-install/include)
target_link_libraries(hello_world PRIVATE ${CMAKE_BINARY_DIR}/FamousHelloLib-install/lib/libhello_lib.a)


