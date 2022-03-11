#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int *arr;
};

int isempty(struct stack *ptr)
{
	if(ptr->top==-1)
	return 1;
	else 
	return 0;
}

int isfull(struct stack *ptr)
{	
	if(ptr->top==ptr->size-1)
	return 1;
	else
	return 0;
}

void push(struct stack *ptr,int val)
{
	if(isfull(ptr))
	printf("\nstack overflow ! you cannot push %d value\n",val);
	else
	{	ptr->top++;
		ptr->arr[ptr->top]=val;
	}
}
int pop(struct stack *ptr)
{
	if(isempty(ptr))
	printf("stack underflow ! you cannot pop any value");
	else
	{
		int a=ptr->arr[ptr->top];
		ptr->top--;
		return a;
	}
}
int main()
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->size=10;
	s->top=-1;
	s->arr=(int*)malloc(s->size*sizeof(int));
	int l,m,n,x,y;
	printf("for push operation enter 1\nfor pop operation enter 2\nfor exit enter 0\n");
	
	do{
        scanf("%d",&l);
	
	switch(l)
	{	case 1:
			{
				printf("\n enter the pushing value\n");
				scanf("%d",&m);
				push(s,m);
				printf("your value %d is succesfully pushed in the stack \n",m);
			}
			break;
	case 2:
		{
			y=pop(s);
			printf("the value %d is poped up from the stack",y);
		}
		break;
	
	default :
		{
			printf("your choice is incorrect ");
		}
		break;
}
}while(l!=0);
printf("thank you for using my stack");	 
return 0;
}

