set (MAIN_SOURCE helloworld.cpp)

add_executable(hello_world ${MAIN_SOURCE})

target_compile_options(hello_world PRIVATE -Wall -Wextra)

if (Boost_FOUND)
  target_compile_definitions(hello_world PRIVATE BAR=1 WITH_BOOST=1)
  target_include_directories(hello_world PRIVATE ${CMAKE_SOURCE_DIR}/lib_src ${BOOST_INCLUDE_DIRS})
else(Boost_FOUND)
  target_compile_definitions(hello_world PRIVATE BAR=1)
  target_include_directories(hello_world PRIVATE ${CMAKE_SOURCE_DIR}/lib_src)
endif (Boost_FOUND)


target_link_libraries(hello_world hello_lib)

