#include "string.h"
#include <stdlib.h>
#include <string.h>

void appendChar(char *str, char ch) {

    // Find the length of the string
    int len = strlen(str);

    // Place the character at the end
    str[len] = ch;

    // Null-terminate the string
    str[len + 1] = '\0';
}

char *make_num(int num) {
    int num1 = num;
    int count = 0;
    char num2;
    while (num != 0) {
        num /= 10;
        count++;
    }

    char *number = new char[count];
    for (int i = (count - 1); i >= 0; i--) {
        num2 = (num1 % 10) + '0';
        number[i] = num2;
        num1 /= 10;
    }
    number[count] = '\0';

    return number;
}

int *my_realloc(int *arr, size_t old_size, size_t size){
    int *buff = arr;
    arr = new int[size];
    for (int i = 0; i < old_size; i++) {
        arr[i] = buff[i];
    }
    
    delete []buff;

    return arr;
}

char *transformation(Array *arr, char *name) {
    char *s = new char[arr->len];
    s[0] = '\0';
    char *num = NULL;
    int len = 0;
    int num1 = 0;
    int count = 0;

    for (int i = 0; i < arr->len; i++) {
        s = strcat(s, name);
        s = strcat(s, ".");
        num1 = i;
        num = make_num(i + 1);
        s = strcat(s, num);
        s = strcat(s, "=");
        num1 = arr->arr[i];
        num = make_num(num1);
        s = strcat(s, num);
        s = strcat(s, "\n");
    }

    return s;
}

Array *transform_to_int(char *str, Array *arr) {
    int counter = 0;
    int len = 1;
    arr = new Array;
    arr->len = len;
    arr->arr = new int[len];
    char *s = strtok(str, "\n");
    while (s != NULL) {
        int len = strlen(s);
        char num;
        for (int i = 0; i < len; i++) {
            if (s[i] == '=') {
                num = s[i + 1];
                break;
            }
        }

        int num1 = num - '0';
        arr->arr[counter] = num1;
        counter++;
        arr->arr = my_realloc(arr->arr, len,counter);
        arr->len = counter;

        s = strtok(NULL, "\n");
    }
    

    return arr;
}