//
// Created by Vojta on 24.01.2023.
//

#include "init.h"

void init(){
    initFolder();
    initFile();
}

void initFolder() {
    if (!CreateDirectory("slovicka", NULL)){
        return;
    }
}

void initFile(){
    FILE* file;
    fopen_s(&file,"slovicka/words.txt","a");
    fclose(file);
}


