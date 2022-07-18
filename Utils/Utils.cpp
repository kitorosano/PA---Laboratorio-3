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

bool onlyContainsNumbers(string str){
    for(char const &c : str) {
        if (isdigit(c) == 0){
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


bool isDoubleWM(string a) {
    bool usedComma = false;
    if(a[0] == '.' && a.length() == 1){
        return false;
    }

    for(char const &c : a) {
        if (isdigit(c) == 0){
            if(c == '.' && !usedComma)
                usedComma = true;
            else
                return false;
        }
    }
    return true;
}

string printDouble(double var)
{
    double value = (int)(var * 100 + .5);
    return to_string((double)value / 100);
}