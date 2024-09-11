#ifndef STRING
#define STRING
#include <stddef.h>

typedef struct Array{
    char *name;
    int *arr;
    size_t len;
}Array;

char *transformation(Array *arr, char *name);
Array *transform_to_int(char *str, Array *arr);

#endif