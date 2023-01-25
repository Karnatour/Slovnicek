//
// Created by Vojta on 25.01.2023.
//

#include "unit.h"
#include "funkce.h"

void loadUnit(int number,char* path) {
    Unit unit;
    char* pointers[10];
    unit.cz = (char *) malloc(100);
    unit.en = (char *) malloc(100);
    pointers[0] = unit.cz;
    pointers[1] = unit.en;
    FILE* file;
    fopen_s(&file,path,"a");
    fgets(unit.cz, sizeof(unit.cz),file);
    fclose(file);

    return
}