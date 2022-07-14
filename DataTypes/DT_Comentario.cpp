//
// Created by Admin on 13/07/2022.
//
#include "DT_Comentario.h"


using namespace std;
DT_Comentario::DT_Comentario(int idComentario,DT_Date* fechaEnvio,DT_Time* horaEnvio,string escritor, string contenido){
    this->idComentario=idComentario;
    this->fechaEnvio = fechaEnvio;
    this->horaEnvio = horaEnvio;
    this->contenido = contenido;
    this->escritor = escritor;
}

DT_Comentario::~DT_Comentario(){
}
int DT_Comentario::getIdComentario(){
    return this->idComentario;
}
DT_Date* DT_Comentario::getFechaEnvio(){
    return this->fechaEnvio;
}
DT_Time* DT_Comentario::getHoraEnvio(){
    return this->horaEnvio;
}
string DT_Comentario::getEscritor(){
    return this->escritor;
}
string DT_Comentario::getContenido(){
    return this->contenido;
}