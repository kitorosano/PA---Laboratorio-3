//
// Created by esteban.rosano on 20/6/2022.
//
#include "UsuarioController.h"
#include "ColeccionesG/KeyString.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/ICollection.h"
using namespace std;

UsuarioController* UsuarioController::instance = NULL;

UsuarioController::UsuarioController() {
    this->usuarioLogeado = NULL;
    this->controller_memory=NULL;
    this->usuarios = new ListDicc();
}

UsuarioController::~UsuarioController(){}

UsuarioController* UsuarioController::getInstance() {
    if (instance == NULL)
        instance = new UsuarioController();
    return instance;
}

Usuario UsuarioController::getUsuarioLogeado(){
    return *this->usuarioLogeado;
}

void UsuarioController::registroJugador(string email,string password,string nickname,string descripcion){
    this->controller_memory= new Jugador(email,password,nickname,descripcion);
}
void UsuarioController::registroDesarrollador(string email,string password,string empresa){
    this->controller_memory= new Desarrollador(email,password,empresa);
}
bool UsuarioController::verificarNickname(string nickname){
    IIterator* iter = usuarios->getIteratorObj();
    if(!this->usuarios)
        return true;
    else if(this->usuarios){
        while (iter->hasNext()) {
            Jugador* jugador=dynamic_cast<Jugador*>(iter->getCurrent());
            if(nickname==jugador->getNickname())
                return false;
        }
    }
    return true;
}
void UsuarioController::confirmarRegistro(){
    if(this->controller_memory) {
        KeyString* key = new KeyString(controller_memory->getEmail());
        this->usuarios->add(this->controller_memory,key);
        this->controller_memory=NULL;
    }
}
void UsuarioController::cancelarRegistro(){
    if(this->controller_memory) {
        delete this->controller_memory;
        this->controller_memory=NULL;
    }
}

void UsuarioController::iniciarSesion(string mail,string password){
    KeyString* key_mail = new KeyString(mail);
    if(!this->usuarios) {
        throw invalid_argument("No hay usuarios en el sistema");
        return;
    }
    Usuario * aux = (Usuario *) (this->usuarios->find(key_mail));
    if (!aux) {
        throw invalid_argument("El usuario no existe en el sistema");
        return;
    }
    if(aux->verificarContraseña(password)){
        this->usuarioLogeado=aux;
    }
    else{
        throw invalid_argument("La contraseña no es valida");
    }
}
void UsuarioController::listarJugadores(){
    IIterator* iter = usuarios->getIteratorObj();
    if(!usuarios)
       return;

    while (iter->hasNext()) {
        //Usuario* usuario = (Usuario*) (iter->getCurrent());
        Jugador* jugador=dynamic_cast<Jugador*>(iter->getCurrent());
        jugador->toString();
        cout<<"----------------------------------------------------";
    }
    delete iter;
}
void UsuarioController::seguirJugador(string nickname) {
    if (!this->usuarios){
        throw invalid_argument("No hay usuarios ingresados en el sistema");
    return;
    }
    Desarrollador* dev=dynamic_cast<Desarrollador*>(usuarioLogeado);
    if(dev)
        return;

    IIterator *iter = this->usuarios->getIteratorObj();

    while(iter->hasNext()){
        Jugador* jugador=dynamic_cast<Jugador*>(iter->getCurrent());
        if(jugador->getNickname()==nickname){

            Jugador* jug_l=dynamic_cast<Jugador*>(usuarioLogeado);
            KeyString* key = new KeyString(nickname);
            jug_l->getjugadores_seguidos()->add(this->controller_memory,key);
            break;
        }
    }
    delete iter;


    throw invalid_argument("El juegador con el nickname ingresado no existe en el sistema");


}