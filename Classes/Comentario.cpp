//
// Created by Davila on 21/6/2022.
//

#include "Comentario.h"

Comentario::Comentario(int idComentario, DT_Date fecha_envio, DT_Time hora_envio, string contenido,
                       Comentario *comentarioAResponder, Jugador *jugador) {
    this->idComentario = idComentario;
    this->fecha_envio = fecha_envio;
    this->hora_envio = hora_envio;
    this->contenido = contenido;
    this->comentarioAResponder = comentarioAResponder;
    this->jugador = jugador;
}

int Comentario::getIdComentario() {
    return this->idComentario;
}

DT_Date Comentario::getFecha_envio() {
    return this->fecha_envio;
}

DT_Time Comentario::getHora_envio() {
    return this->hora_envio;
}

string Comentario::getContenido() {
    return this->contenido;
}

Comentario *Comentario::getComentarioAResponder() {
    return this->comentarioAResponder;
}

Jugador *Comentario::getJugador() {
    return this->jugador;
}

void Comentario::setIdComentario(int idComentario) {
    this->idComentario = idComentario;
}

void Comentario::setFecha_envio(DT_Date fecha_envio) {
    this->fecha_envio = fecha_envio;
}

void Comentario::sethora_envio(DT_Time hora_envio) {
    this->hora_envio = hora_envio;
}

void Comentario::setContenido(string contenido) {
    this->contenido = contenido;
}

void Comentario::setComentarioAResponder(Comentario *comentarioAResponder) {
    this->comentarioAResponder = comentarioAResponder;
}

void Comentario::setJugador(Jugador *jugador) {
    this->jugador = jugador;
}
