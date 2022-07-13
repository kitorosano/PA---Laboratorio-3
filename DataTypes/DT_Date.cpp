//
// Created by Admin on 23/06/2022.
//
#include "DT_Date.h"
#include <iomanip>

using namespace std;

DT_Date::DT_Date(){
    stringstream ssDate;
    auto t = std::time(nullptr);
    auto tm = *localtime(&t);
    ssDate<<put_time(&tm, "%d-%m-%Y");

    this->date = ssDate.str();
}

DT_Date::~DT_Date(){}

string DT_Date::getDate(){
    return this->date;
}