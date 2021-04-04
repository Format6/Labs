/**
 * @mainpage
 * # Загальне завдання
 * 1. **Зробити** програму з показчиками
 * 2. **Визначити** чи є в масиви елементи, що повторюються, якщо є, то створити масив, в якому вказати скiльки разiв якi елементи повторюються.

 */

#include "lib.h"

int main() {

    printf("Laboratory work 12.\nInteraction with the user by input/output to the console\n\nBy Romanenko Dmitro\n\n");
    int main_arr[N] = { 0 };

    printf("Enter 6 variables into an array:");
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &main_arr[i]);
    }

    int* main_result = counter(main_arr);


    return 0;
}

