#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct Node{
    int val;
    struct Node* next;
};

struct Stack
{
    int top;
    struct Node* head;
};

//function to create a stack with fixed no. of elements i.e. max_stack
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

int main(){

    int op1, op2, flag = 1;
    char ch;
    
    printf("Enter your postfix expression (end it with $): ");

    struct Stack *stack = createStack();

    if(stack == NULL){
        printf("Could not create stack!");
    }
    else{

        do{
            scanf("%c", &ch);

            if(isalnum(ch)){
                push(stack, ch - '0');
            }
            else if(ch == '$')
                break;
            else{  //this means ch is an operation symbol

                op1 = pop(stack);
                op2 = pop(stack);

                if(op2 == '$'){
                    flag = 0;
                    break;
                }

                switch (ch)
                {
                case '+':
                    op2 = op2 + op1;
                    break;
                case '-':
                    op2 = op2 - op1;
                    break;
                case '/':
                    op2 = op2/op1;
                    break;
                case '*':
                    op2 = op2 * op1;
                    break;
                case '^':
                    op2 = pow(op2, op1);
                    break;
                default:
                    break;
                }
                
                push(stack, op2);
            }

        }while(ch!='$');

        if(flag == 1){
            printf("Answer: %d", pop(stack));
        }
        else{
            printf("Invalid expression!");
        }
    }

    return EXIT_SUCCESS;
}