#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Stack
{
    int top;
    struct Node* head;
};

struct Stack* createStack()   //dynamic memory stack
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->head = NULL;
 
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
int peek(struct Stack* stack)
{
    return stack->head->val;
}
int pop(struct Stack* stack)
{
    int store;

    if (!isEmpty(stack)){
        struct Node* temp = stack->head;
        stack->head = stack->head->next;
        
        store = temp->val;
        free(temp);
        stack->top--;
        return store;
    }
        
    return '$';
}
void push(struct Stack* stack, int op)
{
    struct Node* store = (struct Node*)malloc(sizeof(struct Node));

    if(store){
        store->next = NULL;
        store->val = op;

        if (!isEmpty(stack)){
            store->next = stack->head;
            stack->head = store;
        }
        else{
            stack->head = store;
        }
        stack->top++;
    }
    else{
        printf("Out of memory!");
    }
}

void display_stack(struct Stack* stack)
{
    struct Node* store = (struct Node*)malloc(sizeof(struct Node));

    if(store){
        store = stack->head;

        if(store == NULL){
            printf("\nStack is Empty!!");
        }
        else{
            printf("\nCurrent Stack is: ");

            while(store!= NULL){
                printf("%d ", store->val);
                store = store->next;
            }
        }

        printf("\n");
    }
    else{
        printf("\nOut of memory!");
    }
}

int main(){

    int v;
    char ch;

    struct Stack *stack = createStack();

    if(stack == NULL){
        printf("Could not create stack!");
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