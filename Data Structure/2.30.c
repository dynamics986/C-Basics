#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 1000000

/* Minimun brackets replacement for a valid string */
int open(char a){
    int result = 0;
    if (a=='(' || a=='[' || a=='{' || a=='<')
        result = 1;
    return result;
}

int close(char b){
    int result = 0;
    if (b==')' || b==']' || b=='}' || b=='>')
        result = 1;
    return result;
}

int match(char a, char b){
    int result = 0;
    if (a=='(' && b==')')
        result = 1;
    if (a=='[' && b==']')
        result = 1;
    if (a=='{' && b=='}')
        result = 1;
    if (a=='<' && b=='>')
        result = 1;
    return result;
}

int main(){
    // construct a stack
    char stack[MAX];
    int top=-1;
    // push: stack[++top] = ...
    // pop : get stack[top] and top--

    // N input
    int N; // 1 <= N <= 1000
    scanf("%d", &N);
    char brackets[MAX];

    // clock_t start = clock();
    for (int i=0; i<N; i++){
        // we save space by using 'replace' only but not 'possible'
        int replace = 0;
        top = -1; 

        // process each line, scanf or fgets?
        scanf("%s",brackets);
        int size = (int)strlen(brackets);
        //printf("size=%d\n",size);
        // printf("brackets = %s\n",brackets);
        // printf("size     = %d\n", size);
        // identify whether it is valid using stacks
        // if open, push; if close, pop, check and change;
        for (int j=0; j<size; j++){
            if ( open(brackets[j]) ){
                stack[++top] = brackets[j];
            }
            else { // close brackets
                if (top < 0){ // open brackets can not be too little
                    replace = -1;
                    break; // not possible, do break 
                }
                else {
                    if ( match(stack[top], brackets[j]) ){
                        top--;
                        // continue; // process next char
                    }
                    else{ // not match, just replacing with others
                        top--;
                        replace++; // since stack[top] is open, must succeed 
                    } 
                }
            }
        }
        // printf("top=%d\n",top);
        if (top >= 0)
            replace = -1; //open brackets can not be too much
        // We can consider them as one kind of pairs to see possible or not
        // since bracket kinds can be replaced
        printf("%d\n", replace);
    }
    // clock_t end = clock();
    // double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    // printf("Time taken for the loop: %f seconds\n", time_taken);
    return 0;
}