#include<stdio.h>
#include<stdlib.h>

int main(){

    int val = 0;
    char ch;


    do{
        scanf("%c", &ch);
        val = val + ch;
    }while(ch!='\n');

    printf("%d", val);

    return EXIT_SUCCESS;
}