cmake_minimum_required(VERSION 3.21)
project(PA___Laboratorio_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA___Laboratorio_3
        main.cpp
        IUsuario.h Usuario.cpp Usuario.h
        UsuarioController.cpp UsuarioController.h
        IVideojuego.h
        VideojuegoController.cpp VideojuegoController.h
        Gen_videojuego.h Gen_videojuego.cpp
        Categoria.h Categoria.cpp Jugador.cpp Jugador.h Suscripcion.cpp Suscripcion.h)
