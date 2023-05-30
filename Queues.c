// Program to Implement Queue using Arrays
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[5], front = -1, rear = -1;

void enqueue(int ele){

    if(rear == SIZE-1) printf("\nQueue is Full");

    else {

        if(front == -1) front = 0;

        queue[++rear] = ele;

        printf("\nInserted value to the queue is : %d ", ele);
    }
}

void dequeue(){

    if(front == -1) printf("Queue is Empty");

    else{

        printf("\nDeleted value of the Queue is : %d ",queue[front++]);

        if(front > rear) front = rear = -1;
    }
}

void display(){

    if(front == -1) printf("\nQueue is Empty");

    else {
        printf("\nQueue Elements are : ");

        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int val, ch;

    while(1){
        
        printf("\nQueue Menu");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");

        printf("\nEnter the choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1 : printf("\n Enter the Elements to be inserted : ");
                 scanf("%d", &val);
                 enqueue(val);
            break;
        
        case 2 : dequeue();
            break;

        case 3 : display();
            break;

        case 4 : return 0;
        
        default: printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}