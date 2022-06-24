//
// Created by esteban.rosano on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_USUARIO_H
#define PA___LABORATORIO_3_USUARIO_H
#include <string>
#include <iostream>
using namespace std;

class Usuario {
private:
    string email;
    string password;

public:
    Usuario(string email, string password);
    virtual ~Usuario();

    string getEmail();
    string getPassword();

    void setEmail(string email);
    void setPassword(string password);
    void confirmarRegistro();
    void cancelarRegistro();
    bool verificarContraseña(string password);

};


#endif //PA___LABORATORIO_3_USUARIO_H
