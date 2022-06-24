cmake_minimum_required(VERSION 3.21)
project(PA___Laboratorio_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA___Laboratorio_3
        main.cpp

        Interfaces/IUsuario.h
        Interfaces/IVideojuego.h
        Interfaces/IPartida.h
        Interfaces/ICategoria.h 

        Controllers/UsuarioController.cpp Controllers/UsuarioController.h
        Controllers/VideojuegoController.cpp Controllers/VideojuegoController.h
        Controllers/PartidaController.cpp Controllers/PartidaController.h 
        Controllers/CategoriaController.cpp Controllers/CategoriaController.h
        Controllers/DatosSuscripcionController.cpp Controllers/DatosSuscripcionController.h

        Classes/Usuario.cpp Classes/Usuario.h Classes/Jugador.cpp Classes/Jugador.h
        Classes/Categoria.h Classes/Categoria.cpp Classes/Videojuego.h Classes/Videojuego.cpp
        Classes/Suscripcion.cpp Classes/Suscripcion.h Classes/DatosSuscripcion.cpp Classes/DatosSuscripcion.h 
        Classes/Partida.cpp Classes/Partida.h Classes/Individual.cpp Classes/Individual.h Classes/Multijugador.cpp Classes/Multijugador.h Classes/Comentario.cpp Classes/Comentario.h 
        Classes/JugadorMultijugador.cpp Classes/JugadorMultijugador.h

        DataTypes/DT_Date.cpp DataTypes/DT_Date.h
        DataTypes/DT_Time.cpp DataTypes/DT_Time.h
        DataTypes/DT_NomDescVideojuego.cpp DataTypes/DT_NomDescVideojuego.h 
        DataTypes/DT_InfoVideojuegoJugador.cpp DataTypes/DT_InfoVideojuegoJugador.h 
        DataTypes/DT_InfoVideojuegoDesarrollador.cpp DataTypes/DT_InfoVideojuegoDesarrollador.h
        DataTypes/DT_MultijugadorVideojuego.cpp DataTypes/DT_MultijugadorVideojuego.h

        DataTypes/E_TipoCategoria.h
        DataTypes/E_MetodoPago.h )
