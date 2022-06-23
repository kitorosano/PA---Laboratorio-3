//
// Created by Davila on 21/6/2022.
//

#include "PartidaController.h"

PartidaController *PartidaController::getInstance() {
    if(instance == NULL)
        instance = new PartidaController;
    return instance;
}
