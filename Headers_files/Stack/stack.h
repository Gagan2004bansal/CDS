#include <stdbool.h>

typedef struct Stack Stack;

Stack *stackCreate(size_t element_size);
void stackDelete(Stack *stack);
bool stackPush(Stack *stack, const void *element);
bool stackPop(Stack *stack);
bool stackPeek(const Stack *stack, void *element);
bool stackIsEmpty(const Stack *stack);