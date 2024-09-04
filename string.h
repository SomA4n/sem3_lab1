#ifndef STRING
#define STRING
#include <stddef.h>

typedef struct Array{
    char *name;
    int *arr;
    size_t len;
}Array;

typedef struct String_el{
    char *key;
    char info;
}String_el;

typedef struct String{
    String_el *string;
}String;



#endif