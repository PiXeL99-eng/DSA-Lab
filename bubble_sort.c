#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int len){
    int temp;
    int swapped = 0;

    for(int i=0; i<len; i++){
        swapped = 0;
        for (int j=0; j<len-i-1; j++){
            if(arr[j]>arr[j+1]){
                swapped = 1;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        if(swapped == 0){
            break;
        }
    }
}
int main()
{
    int len, val;
    printf("Enter length of array: ");
    scanf("%d", &len);

    if(len<=0){
        printf("\nArray length must be greater than 0!");
        return EXIT_SUCCESS;
    }
    int arr[len];

    printf("\nEnter array values:\n");

    for(int i=0; i<len; i++){
        scanf(" %d", &val);
        arr[i] = val;
    }

    bubble_sort(arr, len);

    printf("\nSorted array: ");

    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }

	return EXIT_SUCCESS;
}