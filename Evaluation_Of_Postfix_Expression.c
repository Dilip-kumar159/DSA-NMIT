// Program to Evaluate Postfix Expression 

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 50

int stack[size];
int top = -1;

void push(int ele){
    stack[++top] = ele;
}

int pop(){
    return stack[top--];
}

int main()
{
    char postfix[50], ch;
    int i=0,operand1, operand2;
    printf("Enter the Postfix Expression \n");
    scanf("%s", postfix);

    while((ch = postfix[i++]) != '\0'){

        if(isdigit(ch)) push(ch - '0');

        else{
                operand2 = pop();
                operand1 = pop();

                switch (ch)
                {
                case '+' : push(operand1 + operand2);
                    break;
                case '-' : push(operand1 - operand2);
                    break;
                case '*' : push(operand1 * operand2);
                    break;
                case '/' : push(operand1 / operand2);
                    break;
                case '^' : push(operand1 ^ operand2);
                    break;
                
                default: printf("Invalid operator\n");
                    break;
            }
        }
    } 
        printf("Postfix Expression is : %s", postfix);
        printf("\nResult of Postfix Expression is : %d ", stack[top]);
    return 0;
}