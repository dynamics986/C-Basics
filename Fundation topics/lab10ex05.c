/**
 * Write a C program to read input strings one by one 
 * and check whether each of them is a palindrome, '
 * which reads the same forward or backward, 
 * until the user enters "quit" (case-insensitive).
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome (char input[]){
    int length = (int) strlen(input);
    int result = 1;
    int left = 0;
    int right = length-1;
    for (int i=0;i<length;i++){
        input[i] = tolower(input[i]);
        //printf("%c",input[i]);
    }

    while (left < right){
        if (input[left] != input[right]){
            result = 0;
            break;
        }
        left++;
        right--;
    }

    if (strcmp(input,"quit") == 0)
        result = -1;

    return result;
}

int main(void) {
    int noQuit = 1;
    char str[20];
    int Palindrome = 1;
    while(noQuit){
        fgets(str,20,stdin);
        str[strcspn(str,"\n")] = 0;
        if (isPalindrome(str) == 1){
            printf("Palindrome\n");
        }
        else if (isPalindrome(str) == 0) {
            printf("Not palindrome\n");
        }
        else {
            noQuit = 0;
        }
    }
    printf("Bye\n");
    return 0;
}