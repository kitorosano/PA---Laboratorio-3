//
// Created by Davila on 21/6/2022.
//

#include "Comentario.h"

Comentario::Comentario() {
}

Comentario::Comentario(Jugador *escritor, DT_Date fechaEnvio, DT_Time horaEnvio, string contenido) {
//    setear id
    this->fechaEnvio = fechaEnvio;
    this->horaEnvio = horaEnvio;
    this->contenido = contenido;
    this->escritor = escritor;
}

Comentario::Comentario(Jugador *escritor, DT_Date fechaEnvio, DT_Time horaEnvio, string contenido,Comentario *comentarioAResponder) {
    //    setear id
    this->fechaEnvio = fechaEnvio;
    this->horaEnvio = horaEnvio;
    this->contenido = contenido;
    this->comentarioAResponder = comentarioAResponder;
    this->escritor = escritor;
}

Comentario::~Comentario() {
}

int Comentario::getIdComentario() {
    return this->idComentario;
}

DT_Date Comentario::getFechaEnvio() {
    return this->fechaEnvio;
}

DT_Time Comentario::getHoraEnvio() {
    return this->horaEnvio;
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

void Comentario::setFechaEnvio(DT_Date fechaEnvio) {
    this->fechaEnvio = fechaEnvio;
}

void Comentario::sethoraEnvio(DT_Time horaEnvio) {
    this->horaEnvio = horaEnvio;
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
    stringstream ss;
    ss << "Comentario: " << this->idComentario << " Escrito por: " << this->escritor->getNickname() << " Fecha: "
       << this->fechaEnvio.getDate() << " Hora: " << this->horaEnvio.getTime() << " Contenido: " << this->contenido;
    return ss.str();
}