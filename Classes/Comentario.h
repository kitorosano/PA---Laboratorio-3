//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_COMENTARIO_H
#define PA___LABORATORIO_3_COMENTARIO_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "DataTypes/DT_Fecha.h"
#include "Classes/Jugador.h"
#include "string"
#include <iostream>
using namespace std;

class Comentario : public ICollectible {
private:
    int idComentario;
    Jugador* escritor;
    DT_Fecha* fechaEnvio;
    string contenido;
    Comentario* comentarioAResponder;

public:
    Comentario();
    Comentario(Jugador* escritor, DT_Fecha* fechaEnvio, string contenido);
    Comentario(Jugador* escritor, DT_Fecha* fechaEnvio, string contenido, Comentario* comentarioAResponder);
    ~Comentario();

    int getIdComentario();
    DT_Fecha* getFechaEnvio();
    string getContenido();
    Comentario* getComentarioAResponder();
    Jugador* getEscritor();

    void setIdComentario(int idComentario);
    void setFechaEnvio(DT_Fecha* fechaEnvio);
    void setContenido(string contenido);
    void setComentarioAResponder(Comentario* comentarioAResponder);
    void setEscritor(Jugador* escritor);

    string toString();

};


#endif //PA___LABORATORIO_3_COMENTARIO_H
