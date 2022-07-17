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
int UsuarioController::tipoUsuario(Usuario* user){
    Jugador* jugador=dynamic_cast<Jugador*>(user);
    if(jugador)
        return 1;
    Desarrollador* desarrollador=dynamic_cast<Desarrollador*>(user);
    if(desarrollador)
        return 0;
    return -1;
}

UsuarioController::~UsuarioController(){}

UsuarioController* UsuarioController::getInstance() {
    if (instance == NULL)
        instance = new UsuarioController();
    return instance;
}

Usuario* UsuarioController::getUsuarioLogeado(){
    return this->usuarioLogeado;
}

IDictionary* UsuarioController::getUsuarios(){
    return this->usuarios;
}

void UsuarioController::registroJugador(string email,string password,string nickname,string descripcion){
    if(this->usuarios){
        if(buscarUsuario(email) && buscarUsuario(email)->getEmail()==email){
            cout<<"Error ya existe un usuario en el sistema con el email ingresado!";
        }
    }
        this->controller_memory= new Jugador(email,password,nickname,descripcion);
}
void UsuarioController::registroDesarrollador(string email,string password,string empresa){
    if(this->usuarios){
        if(buscarUsuario(email) && buscarUsuario(email)->getEmail()==email){
            cout<<"Error ya existe un usuario en el sistema con el email ingresado!";
        }
    }
    this->controller_memory= new Desarrollador(email,password,empresa);
}
bool UsuarioController::verificarNickname(string nickname){
    IIterator* iter = usuarios->getIteratorObj();
    if(!this->usuarios)
        return true;
    else if(this->usuarios){
        while (iter->hasNext()) {
            Jugador* jugador=dynamic_cast<Jugador*>(iter->next());
            if(jugador && nickname==jugador->getNickname())
                return false;
        }

    }
    return true;
}
Usuario* UsuarioController::confirmarRegistro(){
    Usuario *user = NULL;
    if(this->controller_memory) {
        KeyString* key = new KeyString(controller_memory->getEmail());
        this->usuarios->add(this->controller_memory,key);
        user = this->controller_memory;
    }
    this->controller_memory=NULL;
    return user;
}
void UsuarioController::cancelarRegistro(){
    if(this->controller_memory) {
        delete this->controller_memory;
        this->controller_memory=NULL;
    }
}

Usuario* UsuarioController::buscarUsuario(string mail){
    if (!this->usuarios)
        return NULL;
    KeyString* key_mail = new KeyString(mail);
    Usuario * aux = (Usuario *) (this->usuarios->find(key_mail));
     if (!aux)
        return NULL;

     else{
         return aux;
     }
}

int UsuarioController::iniciarSesion(string mail,string password){
    KeyString* key_mail = new KeyString(mail);
    if(!this->usuarios) {
        //No hay usuarios en el sistema
        return 1;
    }
    Usuario * aux = (Usuario *) (this->usuarios->find(key_mail));
    if (!aux) {
        //El usuario no existe en el sistema
        return 2;
    }
    if(aux->verificarContraseña(password)){
        this->usuarioLogeado=aux;//inicio session
        return 0;
    }
    else{
        //La contraseña no es valida")
        return 3;
    }
}
void UsuarioController::listarJugadores(){
    IIterator* iter = usuarios->getIteratorObj();
    if(!usuarios)
        return;

    while (iter->hasNext()) {
        //Usuario* usuario = (Usuario*) (iter->getCurrent());
        Jugador* jugador=dynamic_cast<Jugador*>(iter->next());
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
        Jugador* jugador=dynamic_cast<Jugador*>(iter->next());
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