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
    fopen_s(&file,"slovicka/words.txt","r");
    fgets(dict,length,file);
    fclose(file);
    return dict;
}

void compareDictionary(char* ptrDict,char* word){
    const char prefix[3] = "$";
    char *token;
    char firstChar[2];
    for (int i = 0; i < ; ++i) {
        
    }
    token = strtok(ptrDict,prefix);

}

void saveWord(char *number, char *cz, char *en) {
    FILE *file;
    char word[100],*ptr;
    snprintf(word, sizeof(word), "%s$%s$%s$", number, cz, en);
    ptr = loadDictionary();
    compareDictionary(ptr,word);
    fopen_s(&file, "slovicka/words.txt", "a");
    fputs(word, file);
    fclose(file);
}

void convertToSmall(char *word) {
    for (int i = 0; i < strlen(word); ++i) {
        word[i] = tolower(word[i]);
    }
}
