//
// Created by esteban.rosano on 14/7/2022.
//

#include "Utils.h"
#include <iostream>
using namespace std;

void presionaParaContinuar(){
    cout << "Presiona cualquier tecla y luego [Enter] para continuar... ";
    string input;
    cin >> input;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}

bool isInteger(string a) {
    for(char const &c : a) {
        if (isdigit(c) == 0){
            cout<<endl<<"Error: Debe ingresar un numero entero positivo."<<endl;
            system("pause");
            return false;
        }
    }
    return true;
}

bool isIntegerWM(string a) {
    for(char const &c : a) {
        if (isdigit(c) == 0){
            return false;
        }
    }
    return true;
}