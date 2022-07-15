//
// Created by esteban.rosano on 15/7/2022.
//

#include "DT_Fecha.h"
#include <iomanip>      // std::get_time
#include <ctime>        // struct std::tm

DT_Fecha::DT_Fecha() {
    // current date/time based on current system
    time_t now = time(0);
    this->datetime = now;

    // convert now to string form
    tm *ltm = localtime(&now);

    // print various components of tm structure.
    this->anio = 1900 + ltm->tm_year;
    this->mes = 1 + ltm->tm_mon;
    this->dia = ltm->tm_mday;
    this->hora = ltm->tm_hour;
    this->minuto = ltm->tm_min;
    this->segundo = ltm->tm_sec;
}

DT_Fecha::DT_Fecha(int dia, int mes, int anio, int hora, int minuto, int segundo) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;

    struct tm tm = {0};
    istringstream ss(to_string(dia) + "-"+ to_string(mes) + "-" + to_string(anio) + " " + to_string(hora) + ":" + to_string(minuto) + ":" + to_string(segundo));
    ss >> get_time(&tm, "%d-%m-%Y %H:%M:%S");
    time_t time = mktime(&tm);
    this->datetime = time;
}

DT_Fecha::~DT_Fecha() {
}

int DT_Fecha::getDia() {
    return this->dia;
}
int DT_Fecha::getMes() {
    return this->mes;
}
int DT_Fecha::getAnio() {
    return this->anio;
}
int DT_Fecha::getHora() {
    return this->hora;
}
int DT_Fecha::getMinuto() {
    return this->minuto;
}
int DT_Fecha::getSegundo() {
    return this->segundo;
}
time_t DT_Fecha::getDatetime() {
    return this->datetime;
}

int DT_Fecha::getDiferenciaEnSegundos(DT_Fecha* fecha) {
    return difftime(this->datetime, fecha->getDatetime());
}
int DT_Fecha::getDiferenciaEnMinutos(DT_Fecha* fecha) {
    return difftime(this->datetime, fecha->getDatetime()) / 60;
}
int DT_Fecha::getDiferenciaEnHoras(DT_Fecha* fecha) {
    return difftime(this->datetime, fecha->getDatetime()) / 3600;
}

string DT_Fecha::toString() {
    stringstream ss;
    ss << setfill('0') << setw(2) << this->dia << "/" << setw(2) << this->mes << "/" << setw(4) << this->anio << " " << setw(2) << this->hora << ":" << setw(2) << this->minuto << ":" << setw(2) << this->segundo;
    return ss.str();
}