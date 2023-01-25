#include "funkce.h"
#include "init.h"

int main() {
    init();
    int choice;
    int unit;
    boolean loop = TRUE;
    do {
        printf("1. Zalozi novou lekci\n"
               "2. Prida nove slovo\n"
               "3. Prekladac\n"
               "4. Zkouseni\n"
               "5. Edit slova\n"
               "6. Ukonceni programu\n");
        scanf_s("%d", &choice);
        switch (choice) {
            case 1:
                system("cls");
                printf("Zadejte cislo lekce\n");
                scanf_s("%d", &unit);
                createUnit(unit);
                break;
            case 2:
                system("cls");
                printf("Zadejte cislo lekce\n");
                scanf_s("%d", &unit);
                saveWord(unit);
                system("cls");
                break;
            case 3:
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
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                loop = FALSE;
                break;
            default:
                printf("Tato moznost neexistuje\n");
                break;
        }
    } while (loop == TRUE);
    return 0;
}
