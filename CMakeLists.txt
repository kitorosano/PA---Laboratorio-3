cmake_minimum_required(VERSION 3.21)
project(PA___Laboratorio_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA___Laboratorio_3
        main.h

        Interfaces/IUsuario.h
        Interfaces/IVideojuego.h
        Interfaces/IPartida.h
        Interfaces/ICategoria.h 

        Controllers/UsuarioController.cpp Controllers/UsuarioController.h
        Controllers/VideojuegoController.cpp Controllers/VideojuegoController.h
        Controllers/PartidaController.cpp Controllers/PartidaController.h 
        Controllers/CategoriaController.cpp Controllers/CategoriaController.h
        Controllers/DatosSuscripcionController.cpp Controllers/DatosSuscripcionController.h

        Classes/Usuario.cpp Classes/Usuario.h Classes/Jugador.cpp Classes/Jugador.h Classes/Desarrollador.cpp Classes/Desarrollador.h
        Classes/Categoria.h Classes/Categoria.cpp Classes/Videojuego.h Classes/Videojuego.cpp
        Classes/DatosSuscripcion.cpp Classes/DatosSuscripcion.h
        Classes/Partida.cpp Classes/Partida.h Classes/Individual.cpp Classes/Individual.h Classes/Multijugador.cpp Classes/Multijugador.h Classes/Comentario.cpp Classes/Comentario.h 
        Classes/JugadorMultijugador.cpp Classes/JugadorMultijugador.h
        Classes/VideojuegoJugador.cpp Classes/VideojuegoJugador.h

        DataTypes/DT_Date.cpp DataTypes/DT_Date.h
        DataTypes/DT_Time.cpp DataTypes/DT_Time.h
        DataTypes/DT_InfoVideojuego.cpp DataTypes/DT_InfoVideojuego.h
        DataTypes/DT_MultijugadorVideojuego.cpp DataTypes/DT_MultijugadorVideojuego.h
        DataTypes/DT_PartidasIndividualesFinalizadas.cpp DataTypes/DT_PartidasIndividualesFinalizadas.h
        DataTypes/DT_Comentario.cpp DataTypes/DT_Comentario.h

        DataTypes/E_TipoCategoria.h
        DataTypes/E_MetodoPago.h main.h
        DataTypes/E_PeriodoValidez.h

        ColeccionesG/ICollectible.cpp ColeccionesG/ICollectible.h
        ColeccionesG/ICollection.h
        ColeccionesG/IDictionary.cpp ColeccionesG/IDictionary.h
        ColeccionesG/IIterator.h
        ColeccionesG/IKey.cpp ColeccionesG/IKey.h
        ColeccionesG/KeyInt.cpp ColeccionesG/KeyInt.h
        ColeccionesG/KeyString.cpp ColeccionesG/KeyString.h
        ColeccionesG/Lista.cpp ColeccionesG/Lista.h
        ColeccionesG/ListaDicc.cpp ColeccionesG/ListaDicc.h
        ColeccionesG/ListaIterator.cpp ColeccionesG/ListaIterator.h
        ColeccionesG/ListDiccIterator.cpp ColeccionesG/ListDiccIterator.h
        ColeccionesG/ListDiccIteratorKey.cpp ColeccionesG/ListDiccIteratorKey.h
        ColeccionesG/ListDiccIteratorObj.cpp ColeccionesG/ListDiccIteratorObj.h
        ColeccionesG/Nodo.cpp ColeccionesG/Nodo.h
        ColeccionesG/NodoDicc.cpp ColeccionesG/NodoDicc.h
        ColeccionesG/Par.cpp ColeccionesG/Par.h


        Factory/Factory.cpp Factory/Factory.h
        UseCases/AltaUsuario.cpp UseCases/AltaUsuario.h
        UseCases/IniciarSesion.cpp UseCases/IniciarSesion.h
        UseCases/CargarDatosDePrueba.cpp UseCases/CargarDatosDePrueba.h
        UseCases/AgregarCategoria.cpp UseCases/AgregarCategoria.h
        UseCases/PublicarVideojuego.cpp UseCases/PublicarVideojuego.h
        UseCases/EliminarVideojuego.cpp UseCases/EliminarVideojuego.h
        UseCases/VerInformacionDeVideojuego.cpp UseCases/VerInformacionDeVideojuego.h
        UseCases/SuscribirseAVideojuego.cpp UseCases/SuscribirseAVideojuego.h
        UseCases/AsignarPuntajeAVideojuego.cpp UseCases/AsignarPuntajeAVideojuego.h
        UseCases/IniciarPartida.cpp UseCases/IniciarPartida.h
        UseCases/AbandonarPartidaMultijugador.cpp UseCases/AbandonarPartidaMultijugador.h
        UseCases/FinalizarPartida.cpp UseCases/FinalizarPartida.h
        UseCases/RealizarComentario.cpp UseCases/RealizarComentario.h
        UseCases/SeguirJugador.cpp UseCases/SeguirJugador.h
        Classes/Suscripcion.cpp Classes/Suscripcion.h)
