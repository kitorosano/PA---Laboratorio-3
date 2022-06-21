cmake_minimum_required(VERSION 3.21)
project(PA___Laboratorio_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA___Laboratorio_3
        main.cpp
        Interfaces/IUsuario.h
        Controllers/UsuarioController.cpp Controllers/UsuarioController.h
        Interfaces/IVideojuego.h
        Controllers/VideojuegoController.cpp Controllers/VideojuegoController.h
        Classes/Gen_videojuego.h Classes/Gen_videojuego.cpp
        Classes/Categoria.h Classes/Categoria.cpp)
