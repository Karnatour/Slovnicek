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
#include <time.h>
#include <stdbool.h>

void saveWord(int number, char *cz, char *en);

void convertToSmall(char *word);

char *loadDictionary();

int fileLength();

int compareDictionary(char *ptrDict, char *cz, char *en);

void translate(int mode, char *cz, char *en);

void exam(char *ptrCZ,char *ptrEN);

void testUnit(int unit);

#endif //SLOVNICEK_FUNKCE_H
