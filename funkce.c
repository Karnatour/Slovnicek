//
// Created by Vojta on 24.01.2023.
//

#include "funkce.h"

void assemblePath(char* buffer,int number, int mode) {
    //0 = EN, 1 = CZ
    char en[3] = "en", cz[3] = "cz", end[6] = ".txt";
    if (mode == 0) {
        snprintf(buffer, sizeof(buffer), "lekce/%d/%d%s%s", number, number, en, end);
    } else if (mode ==1) {
        snprintf(buffer, sizeof(buffer), "lekce/%d/%d%s%s", number, number, cz, end);
    }
    else{
        printf("Wrong mode at function assemblePath");
        exit(5);
    }
}

void createUnit(int number) {
    createFolder(number);
    createFile(number);
}

void createFile(int number) {
    FILE *file;
    char buffer[50];
    assemblePath(buffer,number,0);
    fopen_s(&file, buffer, "a");
    fclose(file);
    memset(buffer, 0, sizeof(buffer));
    assemblePath(buffer,number,1);
    fopen_s(&file, buffer, "a");
    fclose(file);
}

void createFolder(int number) {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "lekce/%d", number);
    if (!CreateDirectory(buffer, NULL)) {
        printf("Tato lekce jiz existuje\n");
    }
}

void saveWord(int number) {
    FILE *file;
    char suffix[2] = "@";
    char buffer[50], word[40], submit[40];
    printf("Zadejte slovo anglicky\n");
    scanf(" %39[^\n]", word);
    convertToSmall(word);
    snprintf(submit, sizeof(submit), "%s%s", word, suffix);
    assemblePath(buffer,number,0);
    fopen_s(&file, buffer, "a");
    fputs(submit, file);
    fclose(file);
    memset(buffer, 0, sizeof(buffer));
    memset(word, 0, sizeof(word));
    memset(submit, 0, sizeof(submit));
    printf("Zadejte slovo cesky\n");
    scanf(" %39[^\n]", word);
    convertToSmall(word);
    snprintf(submit, sizeof(submit), "%s%s", word, suffix);
    assemblePath(buffer,number,1);
    fopen_s(&file, buffer, "a");
    fputs(submit, file);
    fclose(file);
}

void convertToSmall(char *word) {
    for (int i = 0; i < strlen(word); ++i) {
        word[i] = tolower(word[i]);
    }
}
