//
// Created by Davila on 21/6/2022.
//

#include "Comentario.h"

Comentario::Comentario() {
}

Comentario::Comentario(Jugador *escritor, DT_Fecha* fechaEnvio, string contenido) {
//    setear id
    this->fechaEnvio = fechaEnvio;
    this->contenido = contenido;
    this->escritor = escritor;
}

Comentario::Comentario(Jugador *escritor, DT_Fecha* fechaEnvio, string contenido,Comentario *comentarioAResponder) {
    //    setear id
    this->fechaEnvio = fechaEnvio;
    this->contenido = contenido;
    this->comentarioAResponder = comentarioAResponder;
    this->escritor = escritor;
}

Comentario::~Comentario() {
}

int Comentario::getIdComentario() {
    return this->idComentario;
}

DT_Fecha* Comentario::getFechaEnvio() {
    return this->fechaEnvio;
}

string Comentario::getContenido() {
    return this->contenido;
}

Comentario *Comentario::getComentarioAResponder() {
    return this->comentarioAResponder;
}

Jugador *Comentario::getEscritor() {
    return this->escritor;
}

void Comentario::setIdComentario(int idComentario) {
    this->idComentario = idComentario;
}

void Comentario::setFechaEnvio(DT_Fecha* fechaEnvio) {
    this->fechaEnvio = fechaEnvio;
}

void Comentario::setContenido(string contenido) {
    this->contenido = contenido;
}

void Comentario::setComentarioAResponder(Comentario *comentarioAResponder) {
    this->comentarioAResponder = comentarioAResponder;
}

void Comentario::setEscritor(Jugador *escritor) {
    this->escritor = escritor;
}

string Comentario::toString() {
    return "Comentario: " + to_string(this->idComentario) + " Escrito por: " + this->escritor->getNickname() + " Fecha: " + this->fechaEnvio->toString() + " Contenido: " + this->contenido;
}