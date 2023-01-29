#include "funkce.h"
#include "init.h"

int main() {
    init();
    int choice,translateLoop=1;
    int unit;
    char cz[20];
    char en[20];
    boolean loop = TRUE;
    do {
        printf("1. Prida nove slovo\n"
               "2. Prekladac\n"
               "3. Zkouseni\n"
               "4. Edit slova\n"
               "5. Ukonceni programu\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                system("cls");
                loadDictionary();
                printf("Zadejte slovo ve tvaru lekce,cz,en\n");
                scanf("%d", &unit);
                if (unit <= 0) {
                    printf("Lekce nemuze byt zaporna nebo nulova\n");
                    break;
                }
                scanf(" %19[^\n]", &cz);
                scanf(" %19[^\n]", &en);
                saveWord(unit, cz, en);
                unit = 0;
                memset(cz, 0, sizeof cz);
                memset(en, 0, sizeof en);
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Vyberte mod\n"
                       "1. CZ->EN\n"
                       "2. EN->CZ\n");
                scanf_s("%d", &choice);
                switch (choice) {
                    case 1:
                        do {
                            printf("Zadejte slovo\n");
                            scanf(" %19[^\n]", &cz);
                            translate(choice, cz, en);
                            memset(cz, 0, sizeof cz);
                            printf("Pokud chcete opustit prekladac napiste '0'\n");
                            scanf("%d",&translateLoop);
                        } while (translateLoop!=0);
                        break;
                    case 2:
                        do {
                            printf("Zadejte slovo\n");
                            scanf(" %19[^\n]", &en);
                            translate(choice, cz, en);
                            memset(cz, 0, sizeof en);
                            printf("Pokud chcete opustit prekladac napiste '0'\n");
                            scanf("%d",&translateLoop);
                        } while (translateLoop!=0);
                        break;
                    default:
                        printf("Tato moznost neexistuje\n");
                        break;
                }
                system("cls");
                break;
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
