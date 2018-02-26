cmake_minimum_required(VERSION 3.9)

project(Fdf)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES fdf.c fdf.h)

add_executable(Fdf ${SOURCE_FILES})

target_link_libraries(Fdf ${CMAKE_SOURCE_DIR}/libft/libft.a)
