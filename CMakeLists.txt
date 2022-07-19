cmake_minimum_required(VERSION 3.16.3)

project(fireplace_sim)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
# add_compile_definitions(BUILD=1)

include_directories(include local/include)
link_directories(local/lib)

add_compile_options(-Wall -fPIC)
set(LIBS m dl pthread rtaudio)

add_executable(fireplace src/fireplace.c src/fireplace_dsp.c)
target_link_libraries(fireplace ${LIBS})


