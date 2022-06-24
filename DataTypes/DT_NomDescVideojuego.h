//
// Created by esteban.rosano on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_DT_NOMDESCVIDEOJUEGO_H
#define PA___LABORATORIO_3_DT_NOMDESCVIDEOJUEGO_H

#include <string>

using namespace std;

class DT_NomDescVideojuego {
private:
    string nombre;
    string descripcion;
public:
    DT_NomDescVideojuego(string nombre, string descripcion);
    string getNombre();
    string getDescripcion();
};


#endif //PA___LABORATORIO_3_DT_NOMDESCVIDEOJUEGO_H
