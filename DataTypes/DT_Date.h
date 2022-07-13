//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_DT_DATE_H
#define PA___LABORATORIO_3_DT_DATE_H
#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class DT_Date: public ICollectible {
private:
    string date;
public:
    DT_Date();
    ~DT_Date();

    string getDate();

};
#endif //PA___LABORATORIO_3_DT_DATE_H
