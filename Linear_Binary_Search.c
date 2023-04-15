// Program to implement Linear and Binary Search

#include<stdio.h>
#include<stdlib.h>

void linearSearch(int arr[], int size){

    int key;
    printf("\nEnter the Key : ", &key);
    scanf("%d", &key);

    int flag = 0;

    for(int i=0; i<size; i++){

        if(arr[i] == key){
            printf("\nThe Element is present in the position : %d ", i);
            flag = 1;
            break;
        }
    }

    if(flag == 0) printf("\nThe Element is not present");
}

void binarySearch(int arr[], int size){

    int key;
    int start = 0;
    int end = size-1, flag = 0;

    printf("\nEnter the Key : ", &key);
    scanf("%d", &key);

    while(start <= end){

        int mid = start + (end - start)/2;

        if(arr[mid] == key){
            printf("\nElement is present in the position : %d ", mid);
            flag = 1;
            break;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else end = mid-1;
    }

    if(flag == 0) printf("\nElement is Not present in the Array");
}

void takeInput(int arr[], int size){

    for(int i=0; i<size; i++) scanf("%d", &arr[i]);
}

void swap(int arr[], int i, int j){

    int temp = arr[i];
     arr[i] = arr[j];
    arr[j] = temp;
    
}

void sort(int arr[], int size){

    for(int i=0; i<size; i++){

        for(int j=i+1; j<size; j++){

            if(arr[i] > arr[j]){

                swap(arr, i, j);
            }
        }
    }
}

void printArray(int arr[], int size){

    for(int i=0; i<size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int size;
    int arr[20];
    int choice, choice2;

    do{
        printf("Enter the Choice ");
        printf("\n -> 1. Linear Search ");
        printf("\n -> 2. Binary Search ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1 : printf("\nYou have selected Linear Search");
                
                printf("\nEnter the Size of the Array : ");
                scanf("%d", &size);

                printf("\nEnter the array Elements : ");
                takeInput(arr, size);
                
                linearSearch(arr, size);
        break;

    case 2 : printf("\nYou have selected Binary Search ");
             
                printf("\nEnter the Size of the Array : ");
                scanf("%d", &size);

                printf("\nEnter the array Elements : ");
                takeInput(arr, size);
                
                sort(arr, size);
                printf("\n Printing the Array After Sorting ");
                printArray(arr, size);

                binarySearch(arr, size);
        break;

    default:
            printf("\nInvalid Input Please Enter Above Choice!!");
        break;
    }

    printf("\nFor Exit Press 0 : ");
    printf("\n");
    scanf("%d", &choice2);

} while(choice2 != 0);
    

    return 0;
}