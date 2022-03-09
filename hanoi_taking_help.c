#include<stdio.h>
#include<stdlib.h>

void hanoi(int disk_no, char from, char aux, char to){
    if(disk_no!=0)
    {
        hanoi(disk_no-1, from, to, aux);
        printf("Disk %d is moved from %c to %c\n", disk_no, from, to);
        hanoi(disk_no-1, aux, from, to);
    }
}
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf(" %d", &n);

    hanoi( n, 'A', 'B', 'C');
    return EXIT_SUCCESS;
}