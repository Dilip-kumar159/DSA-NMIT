// Program to Implement Stack Operations

#include<stdio.h>
#include<stdlib.h>

# define max 5

// Global variable declaration

int top = -1;
int stack[max];

int isFull(){

    if(top == max-1) return 1;
    else return 0;
}

int isEmpty(){

    if(top == -1) return 1;

    else return 0;
}

void push(){

    if(isFull()){
        printf("Stack is Overflow \n");
        // getch();
        return;
    }
   else{
            int item;
            printf("Enter the Item to be pushed in stack \n");
            scanf("%d", &item);

            top++;
            stack[top] = item;
        }
}

void pop(){

    int item;

    if(isEmpty()){

        printf("Stack is Underflow \n");
        // getch();
        return;
    }
    else{
        
        item = stack[top];

        top--;

        printf("Popped Element is : %d", item);

        printf("\n");
    }
}

void display(){

    if(top == -1){

        printf("\nNO Elements in Stack \n");
        return;
    }
    int i = top;
    printf("\nStack Elements \n");
    while(i != -1){
        printf("%d\t", stack[i]);
        i--;
    }
}

int main()
{

    int choice;

    while(1){

    printf("\n\nStack Menu \n");
    printf("1. Push Operation\n");
    printf("2. Pop Operation \n");
    printf("3. Display \n");
    printf("4. Exit \n\n");

    printf("Enter the Choice \n");
    scanf("%d", &choice);

        switch (choice){

        case 1: push();
            break;
        case 2: pop();
            break;
        case 3: display();
            break;
        case 4: return 0;
            break;
        default: printf("Invalid Input \n");
            break;
        }
    }
    return 0;
}
