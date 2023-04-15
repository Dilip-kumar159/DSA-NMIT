// Program To Convert Infix To Postfix Expression using Stack.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 50

char stack[size];
int top = -1;

void push(char ele){
    stack[++top] = ele;
}

char pop(){
    return stack[top--];
}

int operatorPrec(char ele){

    if(ele == '^') return 4;

    else if(ele == '*' || ele == '/') return 3;

    else if(ele == '+' || ele == '-') return 2;

    else if(ele == '(') return 1;

    else return 0;
}

int main()
{
    char infix[50], postfix[50];
    char ch, ele;
    int i=0, j=0;
    printf("Enter the Infix Expression \n");
    scanf("%s", infix);

    // Inorder to track the character in stack
    push('#');

    while((ch = infix[i++]) != '\0'){

        if(ch == '(') push(ch);

        else if(isalnum(ch)) postfix[j++] = ch;

        else if(ch == ')'){

            while(stack[top] != '('){

                postfix[j++] = pop();
            } 
                // This pop is to remove the open braces
                ele = pop();
        }

        else{

            while(operatorPrec(stack[top]) >= operatorPrec(ch)){
                 postfix[j++] = pop();
            }
                push(ch);
        }
    }
        while(stack[top] != '#'){
            postfix[j++] = pop();
        }
         postfix[j] = '\0';

         printf("Postfix Expression is : %s", postfix);

    return 0;
}