#include "string.h"
#include <stdlib.h>
#include <string.h>

String *transformation(Array *arr, char *name) {

    String *string = malloc(sizeof(String));
    string->string = malloc(arr->len * sizeof(String_el));
    char *sstr = NULL;
    char *ssstr = NULL;

    char *str = malloc(arr->len);

    for (int i = 0; i < arr->len; i++) {
        sstr = strcat(name, ".");
        char num = (char)i;
        sstr = strcat(sstr, &num);
        sstr = strcat(sstr, "=");
        string->string->key = sstr;
        string->string->info = (char)arr->arr[i];
    }

    return string;
}

