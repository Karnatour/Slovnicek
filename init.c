//
// Created by Vojta on 24.01.2023.
//

#include "init.h"

void init(){
    initFolder();
}

void initFolder() {
    if (!CreateDirectory("lekce", NULL)){
        return;
    }
}
