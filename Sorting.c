// Program to Implement Bubble Sort (ascending order),
// Selection sort (descending order)

#include<stdio.h>
#include<stdlib.h>

// Displaying the Array Elements in the console
void display(int *arr, int n){

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to Swap two elements
void swap(int *arr, int i, int j){

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Taking Input
void takeInput(int *arr, int n){

    printf("Enter the Array Elements\n");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
}

// Bubble Sort (Ascending Order)
void bubbleSort(int *arr, int n){

    for(int i=0; i<n-1; i++){

        for(int j=0; j<n-i-1; j++){

            if(arr[j] > arr[j+1]){

                // Swapping the Element 
                swap(arr, j, j+1);
            }
        }
    }

    printf("\nAfter Using Bubble Sorting\n");
    display(arr, n);
}

// Selection Sort(Descending Order)
void selectionSort(int *arr, int n){

    for(int i=0; i<n; i++){

        int minIndex = i;

        for(int j=i+1; j<n; j++){

            if(arr[j] > arr[minIndex]){

                minIndex = j;
            }
        }
            //swapping the elements
            swap(arr, i, minIndex);
    }

    printf("\nAfter Using Selection Sorting\n");
    display(arr, n);
}


int main()
{
    int n, ch, ch2;
    
    int arr[20];

    while(1){

    printf("\n****** Sorting Menu ******\n");
    printf("1. Bubble Sort (Ascending Order) \n");
    printf("2. Selection Sort (Descending Order) \n");
    printf("3. Exit \n");

    printf("Enter the choice \n");
    scanf("%d", &ch);

        switch (ch){

        case 1 : printf("You have choosen Bubble Sort (Ascending Order)\n");
                 printf("Enter the size of the Array\n");
                 scanf("%d", &n);
                 takeInput(arr, n);
                 bubbleSort(arr, n);
            break;
        
        case 2 : printf("You have choosen Selection Sort (Descending Order)\n");
                 printf("Enter the size of the Array\n");
                 scanf("%d", &n);
                 takeInput(arr, n);
                 selectionSort(arr, n);
            break;

        case 3 : return 0;

        default: printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}