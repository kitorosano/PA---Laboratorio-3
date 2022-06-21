//
// Created by esteban.rosano on 21/6/2022.
//

#include "Usuario.h"

using namespace std;

Usuario::Usuario(string email, string password) {
    this->email = email;
    this->password = password;
}

Usuario::~Usuario() {
}

string Usuario::getEmail() {
    return email;
}

string Usuario::getPassword() {
    return password;
}

void Usuario::setEmail(string email) {
    this->email = email;
}

void Usuario::setPassword(string password) {
    this->password = password;
}