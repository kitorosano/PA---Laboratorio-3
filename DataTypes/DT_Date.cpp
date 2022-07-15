//
// Created by Admin on 23/06/2022.
//
#include "DT_Fecha.h"
#include <iomanip>

using namespace std;

DT_Fecha::DT_Fecha(){
    stringstream ssDate;
    auto t = std::time(nullptr);
    auto tm = *localtime(&t);
    ssDate<<put_time(&tm, "%d-%m-%Y");

    this->date = ssDate.str();
}

DT_Fecha::~DT_Fecha(){}

string DT_Fecha::getDate(){
    return this->date;
}