//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_DT_TIME_H
#define PA___LABORATORIO_3_DT_TIME_H
#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class DT_Time: public ICollectible {
private:
    string time;
public:
    DT_Time();
    ~DT_Time();
    string getTime();

};
#endif //PA___LABORATORIO_3_DT_TIME_H
