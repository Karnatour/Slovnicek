cmake_minimum_required(VERSION 3.24)
project(Slovnicek C)

set(CMAKE_C_STANDARD 23)

add_executable(Slovnicek main.c funkce.c funkce.h init.c init.h unit.c unit.h)
target_compile_definitions(Slovnicek PRIVATE _CRT_SECURE_NO_WARNINGS)