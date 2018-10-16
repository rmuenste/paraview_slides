set (LIB_SOURCE lib_src.cpp lib_src.hpp)

add_library(hello_lib ${LIB_SOURCE}) 

target_compile_options(hello_lib PRIVATE -Wall -Wextra -Werror)

target_compile_definitions(hello_lib PRIVATE FOO=1)

target_include_directories(hello_lib PUBLIC .)
