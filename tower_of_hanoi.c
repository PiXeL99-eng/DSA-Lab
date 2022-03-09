#include<stdio.h>
#include<stdlib.h>

void hanoi(int disk_no, int biggest, char from, char aux, char to){
    if(disk_no==biggest){
        printf("Disk %d is moved from %c to %c\n", biggest-disk_no+1, from, to);
    }
    else{
        hanoi(disk_no, biggest-1, from, to, aux);
        printf("Disk %d is moved from %c to %c\n", biggest-disk_no+1, from, to);
        hanoi(disk_no+1, biggest, aux, from, to);
    }
}
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf(" %d", &n);

    hanoi(1, n, 'A', 'B', 'C');
    return EXIT_SUCCESS;
}