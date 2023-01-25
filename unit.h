//
// Created by Vojta on 25.01.2023.
//

#ifndef SLOVNICEK_UNIT_H
#define SLOVNICEK_UNIT_H

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char *cz;
    char *en;
}Unit;

void loadUnit(int number,char* path);

#endif //SLOVNICEK_UNIT_H
