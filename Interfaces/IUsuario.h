//
// Created by esteban.rosano on 20/6/2022.
//

#ifndef PA_LABORATORIO_3_IUSUARIO_H
#define PA_LABORATORIO_3_IUSUARIO_H

#include <string>
using namespace std;

class IUsuario {
public:
    virtual void registroUsuario(string email, string password) = 0;
    virtual void registroAdicionalDesarrollador(string empresa) = 0;
    virtual void registroAdicionalJugador(string nickname, string descripcion) = 0;
//    virtual void cancelarRegistro() = 0;
    virtual void iniciarSesion(string email, string password) = 0;
//    virtual void cancelarIniciarSesion() = 0;
    virtual Set<Jugador> listarJugadores() = 0;
    virtual void seguirJugador(string nickname) = 0;
    virtual void asignarPuntaje(string videojuego, int puntaje) = 0;
    virtual Set<DT_SuscripcionVideojuego> listarSuscripciones() = 0;
    virtual void seleccionarVideojuego(string videojuego) = 0;
    virtual void seleccionarSuscripcion(int tipo, int metodo_pago) = 0;
    virtual void confirmarSuscripcion() = 0;

};

#endif //PA_LABORATORIO_3_IUSUARIO_H
