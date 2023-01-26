#include "funkce.h"
#include "init.h"

int main() {
    init();
    int choice;
    char unit[3];
    char cz[20];
    char en[20];
    boolean loop = TRUE;
    do {
        printf("1. Prida nove slovo\n"
               "2. Prekladac\n"
               "3. Zkouseni\n"
               "4. Edit slova\n"
               "5. Ukonceni programu\n");
        scanf_s("%d", &choice);
        switch (choice) {
            case 1:
                system("cls");
                loadDictionary();
                printf("Zadejte slovo ve tvaru lekce,cz,en\n");
                scanf_s("%s", &unit);
                scanf_s("%s", &cz);
                scanf_s("%s", &en);
                saveWord(unit,cz,en);
                memset(unit,0,sizeof unit);
                memset(cz,0,sizeof cz);
                memset(en,0,sizeof en);
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Vyberte mód\n"
                       "1. CZ->EN\n"
                       "2. EN->CZ\n");
                scanf_s("%d", &choice);
                switch (choice) {
                    case 1:

                        break;
                    case 2:
                        break;
                    default:
                        printf("Tato moznost neexistuje\n");
                        break;
                }
            case 3:
                break;
            case 4:
                break;
            case 5:
                loop = FALSE;
                break;
            default:
                printf("Tato moznost neexistuje\n");
                break;
        }
    } while (loop == TRUE);
    return 0;
}
