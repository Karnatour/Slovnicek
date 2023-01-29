//
// Created by Vojta on 24.01.2023.
//

#include "funkce.h"

int fileLength() {
    FILE *file;
    int length = 1;
    fopen_s(&file, "slovicka/words.txt", "r");
    while (fgetc(file) != EOF) {
        length++;
    }
    fclose(file);
    return length;
}

char *loadDictionary() {
    //TODO FREE MALOC
    FILE *file;
    int length;
    char *dict;
    length = fileLength();
    dict = (char *) malloc(length);
    fopen_s(&file, "slovicka/words.txt", "r");
    fgets(dict, length, file);
    fclose(file);
    return dict;
}

int compareDictionary(char *ptrDict, char *cz, char *en) {
    char firstChar;
    int length, success = 0;
    size_t wordLengthCZ, wordLengthEN;
    firstChar = cz[0];
    wordLengthCZ = strlen(cz);
    wordLengthEN = strlen(en);
    length = fileLength();
    for (int i = 0; i < length; i++) {
        if (firstChar == ptrDict[i]) {
            for (int j = 0; j < wordLengthCZ; j++) {
                if (cz[j] == ptrDict[j + i]) {
                    success++;
                } else {
                    success = 0;
                }
            }
            if (success == wordLengthCZ) {
                success = 0;
                for (int j = 0; j < wordLengthEN; ++j) {
                    if (en[j] == ptrDict[j + i + wordLengthCZ + 1]) {
                        success++;
                    } else {
                        success = 0;
                    }
                }
            }
            if (success == wordLengthEN) {
                return 1;
            }
        }
    }
    return 0;
}

void saveWord(int number, char *cz, char *en) {
    int result;
    FILE *file;
    char word[100], *ptr;
    snprintf(word, sizeof(word), "%d$%s$%s$", number, cz, en);
    ptr = loadDictionary();
    result = compareDictionary(ptr, cz, en);
    if (result == 0) {
        convertToSmall(word);
        fopen_s(&file, "slovicka/words.txt", "a");
        fputs(word, file);
        fclose(file);
    } else {
        printf("Toto slovo jiz ve slovniku existuje\n");
        system("pause");
    }
    free(ptr);
}

void convertToSmall(char *word) {
    for (int i = 0; i < strlen(word); ++i) {
        word[i] = tolower(word[i]);
    }
}

void translate(int mode, char *cz, char *en) {
    char *ptrDict, firstChar, translated[20];
    int length, success = 0, stop = 1,loop=0,startPos;
    ptrDict = loadDictionary();
    length = fileLength();
    size_t wordLengthCZ, wordLengthEN;
    wordLengthCZ = strlen(cz);
    wordLengthEN = strlen(en);
    memset(translated,0,sizeof translated);
    switch (mode) {
        case 1:
            firstChar = cz[0];
            for (int i = 0; i < length; ++i) {
                if (firstChar == ptrDict[i]) {
                    for (int j = 0; j < wordLengthCZ; ++j) {
                        if (cz[j] == ptrDict[j + i]) {
                            success++;
                        } else {
                            success = 0;
                        }
                        if (success == wordLengthCZ) {
                            for (int k = 0; stop <= 1; ++k) {
                                if (ptrDict[i + k + wordLengthCZ + 1] == '$') {
                                    stop = 2;
                                } else {
                                    translated[k] = ptrDict[i + k + wordLengthCZ + 1];
                                    translated[k + 1] = '\0';
                                }
                            }
                        }
                    }
                }
            }
            system("cls");
            printf("Ceske slovo: %s  Anglicke slovo: %s\n", cz, translated);
            system("pause");
            break;
        case 2:
            firstChar = en[0];
            for (int i = 0; i < length; ++i) {
                if (firstChar == ptrDict[i]) {
                    for (int j = 0; j < wordLengthEN; ++j) {
                        if (en[j] == ptrDict[j + i]) {
                            success++;
                        } else {
                            success = 0;
                        }
                        if (success == wordLengthEN) {
                            i=i-1;
                            while (loop==0){
                                if (ptrDict[i-1]=='$'){
                                    startPos = i;
                                    loop=1;
                                }
                                else{
                                    i--;
                                }
                            }
                            for (int k = 0; stop <= 1; ++k) {
                                if (ptrDict[startPos+k] == '$') {
                                    stop = 2;
                                } else {
                                    translated[k] = ptrDict[i+k];
                                    translated[k + 1] = '\0';
                                }
                            }
                        }
                    }
                }
            }
            system("cls");
            printf("Anglicke slovo: %s  Ceske slovo: %s\n", en, translated);
            system("pause");
            break;
        default:
            printf("Tato moznost neexistuje\n");
            exit(1);
    }

}