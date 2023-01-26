//
// Created by Vojta on 24.01.2023.
//

#ifndef SLOVNICEK_FUNKCE_H
#define SLOVNICEK_FUNKCE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <ctype.h>

void saveWord(char* number,char* cz,char* en);
void convertToSmall(char* word);
char* loadDictionary();
int fileLength();
void compareDictionary(char* ptrDict,char* word);

#endif //SLOVNICEK_FUNKCE_H
