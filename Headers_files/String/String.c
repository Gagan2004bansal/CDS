#include "String.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 16

static void resizeString(String *str, size_t newCapacity){
    char* newData = realloc(str->data, newCapacity);
    if(newData){
        str -> data = newData;
        str -> capacity = newCapacity;
    }
    else{
        perror("Failed to resize String");
        exit(EXIT_FAILURE);
    }
}

String create(){
    String str;
    str.capacity = INITIAL_CAPACITY;
    str.data = malloc(str.capacity);

    if(!str.data){
        perror("Failed to allocate memory for string");
        exit(EXIT_FAILURE);
    }

    str.data[0] = '\0';
    str.length = 0;
    return str;
}

void freeS(String *str){
    if(str->data){
        free(str->data);
        str -> data = NULL;
        str -> capacity = 0;
        str -> length = 0;
    }
}

void appendS(String *str, const char* suffix){
    size_t suffixLength = strlen(suffix);
    if(str -> length + suffixLength >= str -> capacity){
        resizeString(str, str->capacity + suffixLength + 1);
    }
    strcat(str->data, suffix);
    str->length += suffixLength;
}

size_t lenghtS(const String *str){
    return str -> length;
}

const char* getS(const String *str){
    return str -> data;
}

void readS(String *str){
    int ch;
    str -> length = 0;

    while((ch = getchar()) != '\n' && ch != EOF){
        if(str->length + 1 >= str -> capacity){
            resizeString(str, str -> capacity * 2);
        }
        str->data[str->length++] = ch;
    }
    str->data[str->length] = '\0';
}

bool isemptyS(const String* str){
    return str -> length == 0;
}

void rep_substring(String *str, const char* old_sub, const char* new_sub){
    char* pos;
    size_t oldLen = strlen(old_sub);
    size_t newLen = strlen(new_sub);

    while((pos = strstr(str->data, old_sub)) != NULL){
        size_t lenBeforeSub = pos - str->data;
        size_t new_size = str->length - oldLen + newLen;
        if(new_size >= str->capacity){
            resizeString(str, new_size + 1);
        }

        memmove(pos + newLen, pos + oldLen, str->length - lenBeforeSub - oldLen + 1);
        memmove(pos, new_sub, newLen);
        str -> length = new_size;
    }
}

void reverseS(String *str) {
    size_t start = 0;
    size_t end = str->length - 1;
    while (start < end) {
        char temp = str->data[start];
        str->data[start] = str->data[end];
        str->data[end] = temp;
        start++;
        end--;
    }
}