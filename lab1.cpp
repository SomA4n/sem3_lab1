#include <readline/chardefs.h>
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include <readline/readline.h>

int scan_positive(int *adr){
    int res = 0;
    int scan_err = 0;
    while(1){
        scan_err = scanf("%d", &res);
        if (scan_err == EOF){
            return 0;
        } else if (scan_err == 0){
            scanf("%*s");
        } else if (res < 0){
            continue;
        } else{
            *adr = res;
            break;
        }
    }
    scanf("%*[^ \n]");
    getchar();

    return -1;
}

int main () {
    int num = 0;
    int len = 0;

    Array *arr = NULL;
    char *str = NULL;
    printf("Введите количество симолов в массиве: \n");
    scan_positive(&len);
    arr = new Array;
    arr->len = len;
    arr->arr = new int[len];
    arr->name = readline("Введите название массива: \n");
    for (int i = 0; i < arr->len; i++) {
        scanf("%d", (arr->arr + i));
    }


    while (1) {
        printf("Введите номер операции: \n"
                "1. перевести массив в char* \n"
                "2. перевести массив в const char* \n"
                "3. перевести массив в std::string \n"
                "4. перевести строку в массив \n");
        if (!scan_positive(&num)) break;
        if (num == 1) {
            str = transformation(arr, arr->name);
            printf("%s", str);
        }
        if (num == 4) {
            Array *arr1 = transform_to_int(str, arr1);
            for (int i = 0; i < arr->len; i++) {
                printf("%d", arr->arr[i]);
            }
            printf("\n");
        }
    }
}