//
// Created by Admin on 13/07/2022.
//

#ifndef MAIN_CPP_DT_COMENTARIO_H
#define MAIN_CPP_DT_COMENTARIO_H
#include "Classes/Jugador.h"
#include "Classes/Multijugador.h"
#include <string>
using namespace std;

class DT_Comentario : public ICollectible {
private:
    int idComentario;
    DT_Fecha* fechaEnvio;
    string escritor;
    string contenido;
public:
    DT_Comentario(int idComentario,DT_Fecha* fechaEnvio,string escritor, string contenido);
    ~DT_Comentario();
    int getIdComentario();
    DT_Fecha* getFechaEnvio();
    string getEscritor();
    string getContenido();
};
#endif //MAIN_CPP_DT_COMENTARIO_H
