/* Program to simulate the working of the Singly Linked List providing the following
operations
-> Display & insert function.
-> Delete from the Beginning and end.
-> Delete at a given position or element. */

#include<stdio.h>
#include<stdlib.h>

// creation of Node
 typedef struct node{
    int data;
    struct node *next;
} node;

node* head = NULL;

// Inserting a Node
void insert(){
    
    node *newNode, *temp;
    int item;
    temp = head;

    newNode = (node*)malloc(sizeof(node));
    printf("Enter Value\n");
    scanf("%d", &item);

    if(head == NULL){

        newNode->data = item;
        head = newNode;
        newNode->next = NULL;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        newNode->data = item;
        temp->next = newNode;
        newNode->next = NULL;
        printf("Node Inserted\n");
    }
}

// Displaying the Linked list
void display(){

    node* temp = head;

    if(head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    else{
        
        printf("Linked List are \n");

        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL \n");
    }
}

// Deleting from the Beginning
void delete_front(){
    
    node* temp;
    temp = head;

    if(temp == NULL){
        printf("Linked List is Empty \n");
        return;
    }
    else{

        head = head->next;
        free(temp);
        printf("Node Deleted\n");
    }
}

// Deleting from the end
void delete_end(){

    node* temp = head;
    node* prev;

    if(head == NULL){
        printf("Linked List is Empty \n");
    }
    else if(temp->next == NULL){
            head = NULL;
            free(temp);
            printf("Node Deleted if it contains only 1\n");
    }
    else{
         
         while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
         }
            prev->next = NULL;
            free(temp);
            printf("Node Deleted \n");
    }
}

// Deleting At the given Position or Element
void delete_atPosition(){

        node* temp;
        node* prev;
        temp = head;
        int key;

        printf("Enter the Element to Delete\n");
        scanf("%d", &key);

        //case 1 no list
        if(head == NULL){
            printf("Linked list is empty\n");
        }
        else{

            // case 2 first node is the key
            if(temp != NULL && temp->data == key){
                head = head->next;
                free(temp);
            }
            else{

                // case 3 Element is somewhere in the middle node
                while(temp != NULL && temp->data != key){  
                        prev = temp;
                        temp = temp->next;
                }

                // case 4 element not found in the linked list
                if(temp == NULL){
                    printf("Element is not found in the linked List\n");
                    return;
                }

                prev->next = temp->next;
                free(temp);
            }
        }
}

int main()
{
    
    int choice;

    while(1){

        printf("******** Linked List Operations ********\n");
        printf("1. Insert\n");
        printf("2. Delete From Beginning\n");
        printf("3. Delete From End\n");
        printf("4. Delete at the given Element\n");
        printf("5. Display\n");
        printf("6. Exit \n");

        printf("Enter the Choice \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1 : insert();
            break;
        
        case 2 : delete_front();
            break;
        
        case 3 : delete_end();
            break;

        case 4 : delete_atPosition();
            break;
        
        case 5 : display();
            break;

        case 6 : return 0;
        
        default: printf("Invalid Choice \n");
            break;
        }
    }

    return 0;
}
