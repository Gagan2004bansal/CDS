#include<stdio.h>
#include "Headers_files/Stack/stack.h"
#include "Headers_files/Queue/queue.h"
int main(){

    /* -------------- Stack -------------*/

    Stack *stack = stackCreate(sizeof(int));

    if (!stack) {
        printf("Failed to create stack.\n");
        return 1;
    }

    int values[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; ++i) {
        if (!stackPush(stack, &values[i])) {
            printf("Failed to push element onto the stack.\n");
            stackDelete(stack);
            return 1;
        }
    }

    printf("Stack contents: ");
    while (!stackIsEmpty(stack)) {
        int value;
        if (stackPeek(stack, &value)) {
            printf("%d ", value);
        }
        stackPop(stack);
    }
    printf("\n");
    
    stackDelete(stack);

    /* -------------- Queue -------------*/

    Queue *queue = queueCreate(sizeof(int));
    
    if(!queue){
        printf("Failed to create queue.\n");
        return 1;
    }
    
    char value[] = {'a','b','c','d','e','f'};
    
    for(int i=0;i<6;i++){
    	if(!queueEnqueue(queue,&value[i])){
    	    printf("Failed to push element onto the queue.\n");
    	    queueDelete(queue);
    	    return 1;
    	}
    }
    
    printf("queue contains: ");
    
    while(!queueIsEmpty(queue)){
    	char val;
    	if(queuePeek(queue,&val)){
    	    printf("%c ",val);
    	}
    	queueDequeue(queue);
    }
    
    printf("\n");
    
    queueDelete(queue);

    return 0;
}