//
// Created by Admin on 23/06/2022.
//
#include "DT_Time.h"
#include <iomanip>

DT_Time::DT_Time(){

}
DT_Time::~DT_Time(){
    stringstream ssTime;
    auto t = std::time(nullptr);
    auto tm = *localtime(&t);
    ssTime<<put_time(&tm, "%H:%M:%S");
    this->time = ssTime.str();
}
string DT_Time::getTime(){
    return this->time;
}