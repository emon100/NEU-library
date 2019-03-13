cmake_minimum_required(VERSION 3.13)
project(library C)

set(CMAKE_C_STANDARD 99)

add_executable(library main.c login.c admin.c manage.c information.c readercenter.c)