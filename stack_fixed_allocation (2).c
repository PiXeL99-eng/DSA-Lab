#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int top;
    int max_stack;
    int* array;
};

//function to create a stack with fixed no. of elements i.e. max_stack
struct Stack* createStack( int max_stack )
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->max_stack = max_stack;
 
    stack->array = (int*)malloc(stack->max_stack * sizeof(int));
 
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
int peek(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top] ;
    return 0;
}
int pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return 0;
}
void push(struct Stack* stack, int op)
{
    if(stack->top+1 == stack->max_stack){
        printf("\nStack Overflow!!\n");
    }
    else{
        stack->array[++stack->top] = op;
    }
}

void display_stack(struct Stack* stack){
    int len = stack->top;

    if(len == -1){
        printf("\nStack is Empty!!");
    }
    else{
        printf("\nCurrent Stack is: ");

        for(; len>-1; len--){
            printf("%d ", stack->array[len]);
        }
    }

    printf("\n");
}

int main(){

    int len, v;
    char ch;
    
    printf("Enter length of your required Stack: ");
    scanf("%d", &len);

    struct Stack *stack = createStack(len);

    if(stack == NULL){
        printf("Could not create stack, memory insufficient!");
    }
    else{

        do
        {
            printf("\n1. Push to Stack: ");
            printf("\n2. Pop from Stack: ");
            printf("\n3. Peek the Stack: ");
            printf("\n4. Display the entire Stack: ");
            printf("\n5. Exit");
            printf("\nEnter your choice(1-5): ");
            fflush(stdin);
            scanf("%c", &ch);

            switch(ch)
            {
            case '1':
                printf("\nEnter the value to push: ");
                fflush(stdin);
                scanf("%d", &v);
                push(stack, v);
                display_stack(stack);
                break;
            case '2':
                v = pop(stack);
                printf("\nValue popped is: %d", v);
                display_stack(stack);
                break;
            case '3':
                v = peek(stack);
                printf("\nTop most element of Stack is: %d", v);
                display_stack(stack);
                break;
            case '4':
                display_stack(stack);
                break;
            case '5':
                printf("\nPROGRAM TERMINATED!!");
                break;
            default :
                printf("\nWrong Entry!!\n");
                break;
            }

        }while(ch!='5');
    }

    return EXIT_SUCCESS;
}