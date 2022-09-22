cmake_minimum_required(VERSION 3.23)
project(labProgettazioneOS C)

set(CMAKE_C_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_executable(labProgettazioneOS main.c)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
