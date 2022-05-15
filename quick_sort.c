#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high){
    int temp, index = low;
    low = low+1;

    while(low<=high){
        if(arr[low]<arr[index]){
            temp = arr[index];
            arr[index] = arr[low];
            arr[low] = arr[index+1];
            arr[index+1] = temp;
            index++;
        }

        low++;
    }

    return index;
}

void quick_sort(int arr[], int low, int high){

    int index = partition(arr, low, high);

    if(low<=index-1){
        quick_sort(arr, low, index-1);
    }
    if(index+1<=high){
        quick_sort(arr, index+1, high);
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

    quick_sort(arr, 0, len-1);

    printf("\nSorted array: ");

    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }

	return EXIT_SUCCESS;
}