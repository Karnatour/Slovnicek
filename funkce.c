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
    int length, success = 0, stop = 1, loop = 0, startPos;
    ptrDict = loadDictionary();
    length = fileLength();
    size_t wordLengthCZ, wordLengthEN;
    wordLengthCZ = strlen(cz);
    wordLengthEN = strlen(en);
    memset(translated, 0, sizeof translated);
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
            free(ptrDict);
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
                            i = i - 1;
                            while (loop == 0) {
                                if (ptrDict[i - 1] == '$') {
                                    startPos = i;
                                    loop = 1;
                                } else {
                                    i--;
                                }
                            }
                            for (int k = 0; stop <= 1; ++k) {
                                if (ptrDict[startPos + k] == '$') {
                                    stop = 2;
                                } else {
                                    translated[k] = ptrDict[i + k];
                                    translated[k + 1] = '\0';
                                }
                            }
                        }
                    }
                }
            }
            system("cls");
            printf("Anglicke slovo: %s  Ceske slovo: %s\n", en, translated);
            free(ptrDict);
            system("pause");
            break;
        default:
            printf("Tato moznost neexistuje\n");
            free(ptrDict);
            exit(1);
    }

}

void testUnit(int unit) {
    char *ptrDict, *ptrCZ, *ptrEN;
    int loopCZ, loopEN, x, y, czI = 0, enI = 0;
    size_t length;
    length = fileLength();
    ptrCZ = (char *) malloc(length);
    ptrEN = (char *) malloc(length);
    ptrDict = loadDictionary();
    for (int i = 0; i < length; ++i) {
        if (unit + '0' == ptrDict[i]) {
            x = i + 2;
            loopCZ = 0;
            while (loopCZ == 0) {
                if (ptrDict[x] == '$') {
                    loopCZ = 1;
                    ptrCZ[czI] = '$';
                    czI++;
                    loopEN = 0;
                    y = x + 1;
                    while (loopEN == 0) {
                        if (ptrDict[y] == '$') {
                            loopEN = 1;
                            ptrEN[enI] = '$';
                            enI++;
                        } else {
                            ptrEN[enI] = ptrDict[y];
                            enI++;
                            y++;
                        }
                    }
                } else {
                    ptrCZ[czI] = ptrDict[x];
                    czI++;
                    x++;
                }
            }
        }
    }
    free(ptrDict);
    ptrCZ[czI] = '\0';
    ptrEN[enI] = '\0';
    exam(ptrCZ, ptrEN);
}

void exam(char *ptrCZ, char *ptrEN) {
    system("cls");
    size_t time = 60;
    unsigned int mistake = 0, correct = 0;
    const char suffix[2] = "$";
    char *cztoken, *entoken, *rest = NULL,*rest2=NULL, answer[20];
    cztoken = strtok_s(ptrCZ, suffix, &rest);
    entoken = strtok_s(ptrEN, suffix, &rest2);
    while (true) {
        printf("Prelozte slovo %s do anglictiny\n", cztoken);
        scanf(" %19[^\n]", &answer);
        if (strcmp(answer, entoken) == 0) {
            printf("Spravne!\n");
            correct++;
        } else {
            printf("Spatne. Spravne slovo bylo %s\n", entoken);
            mistake++;
        }
        system("pause");
        system("cls");
        cztoken = strtok_s(NULL, suffix, &rest);
        entoken = strtok_s(NULL, suffix, &rest2);
        if (entoken==NULL){
            break;
        }
    }
    free(ptrCZ);
    free(ptrEN);
    printf("Uspesnost: %d odpovedi spravne %d odpovedi spatne\n",correct,mistake);
}