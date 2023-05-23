cmake_minimum_required(VERSION 3.24)
project(projet_vecteur C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_vecteur main.c shapes.c shapes.h fonctions.c fonctions.h area.c area.h id.c)
