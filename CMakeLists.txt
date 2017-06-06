cmake_minimum_required(VERSION 3.6)
project(Euler)

set(CMAKE_C_STANDARD 99)

add_executable(Modified-Euler modified-euler.c)
add_executable(Runge-Kutta runge-kutta.c)
add_executable(Modified-Euler-System modified-euler-system.c)
add_executable(Runge-Kutta-System runge-kutta-system.c)
