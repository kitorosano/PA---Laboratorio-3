cmake_minimum_required(VERSION 3.21)
project(PA___Laboratorio_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA___Laboratorio_3
        IUsuario.h
        main.cpp UsuarioController.cpp UsuarioController.h)
