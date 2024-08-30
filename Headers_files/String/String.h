#ifndef STRING
#define STRING

#include <stddef.h> 
#include <stdbool.h>

typedef struct {
    char* data;
    size_t length;
    size_t capacity;
} String;

// functions
String create();
void freeS(String *str);
void appendS(String *str, const char* suffix);
size_t lenghtS(const String *str);
const char* getS(const String *str);
void readS(String *str);
bool isemptyS(const String* str);
void rep_substring(String *str, const char *old_sub, const char *new_sub);
void reverseS(String *str);

#endif