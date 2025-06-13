#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 257

/* Evaluate Postfix Expression */
int factorial(int a){
    int result = 1; // handle factorial !
    if (a >= 0)
        for (int i=a; i>0; i--)
            result *= i;
    else
        result = -1; // print corresponding message
    return result;
}

int operation4(int a, int b, char c){
    int result; // handle + - * /
    if (c=='+')
        result = a+b;
    else if (c=='-')
        result = a-b;
    else if (c=='*')
        result = a*b;
    else if (c=='/')
        result = a/b; //handle exceptions in main function
    return result;
}

char stringToChar(char str[]) {
    if (str == NULL || str[0] == '\0' || str[1] != '\0') {
        return '\0';
    }
    return str[0];
}

int operator1(char c){
    if (c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    else 
        return 0;
}

int isNotOperator(char* c){
    if (strcmp(c,"+")*strcmp(c,"-")*strcmp(c,"*")*strcmp(c,"/")*strcmp(c,"!")){
        //printf("%d %d %d %d %d\n",strcmp(c,"+"),strcmp(c,"-"),strcmp(c,"*"),strcmp(c,"/"),strcmp(c,"!"));
        return 1;
    }
    else
        return 0;
}

int main(){
    // m test cases
    int m;
    scanf("%d ", &m);
    // process each sequences
    for (int i=0; i<m; i++){
        int stack[MAX];
        int top = -1;
        // read and atoi for operands
        int well = 1;
        char sequence[MAX];
        // scanf read tokens one by one, feasible but inefficient
        // fgets get things done once and for all, great with strtok
        fgets(sequence,MAX,stdin);
        int size = (int)strlen(sequence);
        if (sequence[size-1]=='\n')
            sequence[size-1]='\0';
        // process each token
        char delim[] = " ";
        char *token;
        token = strtok(sequence,delim); // sample
        // how to see whether token is number 0
        // if we do not use complement, do the following
        // int num = atoi(token);
        // int len = (int)strlen(token);
        // if ( num!=0 || (len==1 && token[0]==0) )
        //     printf("operand\n");
        // if meet operand, push

        // the following sequence contents
        while (token != NULL) {
            //printf("Token: [%s]\n", token);
            //printf("stack[%d]=%d\n", top, stack[top]);
            
            if ( isNotOperator(token) ){ // is operand, push in stack
                int num = atoi(token);
                stack[++top] = num;
            }
            else { // if meet operator
                char operator = stringToChar(token);
                //printf("%c\n",operator);
                if (operator1(operator)){ // "+-*/" , pop 2 int, handle division by 0
                    if (stack[top]==0 && operator=='/'){
                        printf("division by zero\n");
                        well=0;
                        break;
                    }
                    else {
                        stack[top-1] = operation4(stack[top-1], stack[top], operator);
                        top--;
                    }
                }
                else if (operator == '!'){ //if factorial, pop 1 int
                    stack[top] = factorial(stack[top]); // put back to stack 
                    // handle exception(stop read, break loop)
                    if (stack[top] == -1){
                        printf("factorial of an negative number\n");
                        well=0;
                        break;
                    }
                }
            }
            token = strtok(NULL, delim); // call with NULL to continue
            // put it before while condition to avoid segmentation fault
        }
        // printf("top=%d\n",top);
        if (well)
            printf("%d\n",stack[top]);
    }
    return 0;
}

