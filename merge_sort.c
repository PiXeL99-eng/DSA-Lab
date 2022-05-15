#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r){

    int p_len = m-l+1;
    int s_len = r-m;

    int p_arr[p_len];
    int s_arr[s_len];

    int i, j;

    for(i=0; i<p_len; i++){
        p_arr[i] = arr[l+i];
    }

    for(i=0; i<s_len; i++){
        s_arr[i] = arr[m+1+i];
    }
    
    i=0;
    j=0;

    while(i<p_len && j<s_len){
        if(s_arr[j]<p_arr[i]){
            arr[l] = s_arr[j];
            j++;
        }
        else{
            arr[l] = p_arr[i];
            i++;
        }

        l++;
    }

    while (i<p_len)
    {
        arr[l] = p_arr[i];
        i++;
        l++;
    }
        
    while (j<s_len)
    {
        arr[l] = s_arr[j];
        j++;
        l++;
    }
}

void merge_sort(int arr[], int low, int high){
    if(low<high){
        int middle = low + (high-low)/2;

        merge_sort(arr, low, middle);
        merge_sort(arr, middle+1, high);

        merge(arr, low, middle, high);
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

    merge_sort(arr, 0, len-1);

    printf("\nSorted array: ");

    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }

	return EXIT_SUCCESS;
}