//
// Created by esteban.rosano on 20/6/2022.
//

#ifndef PA___LABORATORIO_3_USUARIOCONTROLLER_H
#define PA___LABORATORIO_3_USUARIOCONTROLLER_H

#include "IUsuario.h"

class UsuarioController: public IUsuario {
public:
    UsuarioController();
    UsuarioController* getInstance();

    void registroUsuario(string email, string password);
    void registroAdicionalDesarrollador(string empresa);
    void registroAdicionalJugador(string nickname, string descripcion);
//    void cancelarRegistro();
    void iniciarSesion(string email, string password);
//    void cancelarIniciarSesion();
    Set<Jugador> listarJugadores();
    void seguirJugador(string nickname);
    void asignarPuntaje(string videojuego, int puntaje);
    Set<DT_SuscripcionVideojuego> listarSuscripciones();
    void seleccionarVideojuego(string videojuego);
    void seleccionarSuscripcion(int tipo, int metodo_pago);
    void confirmarSuscripcion();

    virtual ~UsuarioController();
private:
    static UsuarioController* instance;
    Usuario* usuarioSeleccionado;
    Videojuego* videojuegoSeleccionado;
    Suscripcion* suscripcionSeleccionada;
};


#endif //PA___LABORATORIO_3_USUARIOCONTROLLER_H
