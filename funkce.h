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

void assemblePath(char* buffer,int number,int mode);

void createUnit(int number);
void createFile(int number);
void createFolder(int number);
void saveWord(int number);
void convertToSmall(char* word);
void loadUnit(int number,char* path);

#endif //SLOVNICEK_FUNKCE_H
