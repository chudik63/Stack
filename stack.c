#include <stdio.h>
#include <stdlib.h>
 
typedef struct tag_obj 
{
    int data;
    struct tag_obj* next;
} OBJ;

OBJ* push(OBJ* top, int data) 
{
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ* pop(OBJ* top) 
{
    if(top == NULL)
        return top;

    OBJ* ptr_next = top->next;
    free(top);
    return ptr_next;
}

void show(const OBJ* top) 
{
    const OBJ* current = top;
    while(current) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(void) {
    OBJ* top = NULL;
    int request;
    int count;
    while(1) 
    {
        printf("to push enter 1, to pop - 2, to show the stack - 3, to quit - 4\n");
        scanf("%d", &request);
        if (request == 1)
        {   
            scanf("%d", &count);
            top = push(top, count);
        }
        else if (request == 2)
        {
            top = pop(top);
        }
        else if (request == 3)
        {   
            puts("\nStack:");
            show(top);
            puts("\n");
        }
        else
        {
            break;
        }
    }

    return 0;
}