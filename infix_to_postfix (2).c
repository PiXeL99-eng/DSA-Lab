#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Stack
{
    int top;
    int max_stack;
    char* array;
};

//function to create a stack with fixed no. of elements i.e. max_stack
struct Stack* createStack( int max_stack )
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->max_stack = max_stack;
 
    stack->array = (char*)malloc(stack->max_stack * sizeof(char));
 
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

int prec(char c){    //precendence of symbols, higher precendence means higher integer returned
    switch (c)
    {
    case '+':
    case '-':
        return 1;
        break;

    case '/':
    case '*':
        return 2;
        break;

    case '^':
        return 3;
        break;

    default:
        return -1; //if the character is $ or (, then also return -1
        break;
    }
}
int main(){

    int len, k=0;
    
    printf("Enter length of your infix expresssion: ");
    scanf("%d", &len);

    char exp[len], output[len], ch, temp;

    printf("Enter your infix expresssion: ");
    scanf("%s", exp);

    struct Stack *stack = createStack(len);

    if(stack == NULL){
        printf("Could not create Stack, memory insufficient!");
    }
    else{

        for( int i=0; i<len; i++){
            ch = exp[i];

            if(isalnum(ch)){
                output[k] = ch;
                k++;
            }
            else if(ch == '('){
                push(stack, ch);
            }
            else if(ch == ')'){
                temp = pop(stack);

                while(temp!='(' && temp!='$'){
                    output[k] = temp;
                    k++;
                    temp = pop(stack);
                }
            }
            else{  //this means ch is an operation symbol
                if(prec(peek(stack))<prec(ch)){
                    push(stack, ch);
                }
                else{
                    while(prec(peek(stack))>=prec(ch) && temp!='$'){
                        temp = pop(stack);
                        output[k] = temp;
                        k++;
                    }

                    push(stack, ch);
                }

            }

        }

        while(!isEmpty(stack)){
            output[k++] = pop(stack);
        }

        output[k] = '\0';
        printf("%s", output);
    }

    return EXIT_SUCCESS;
}