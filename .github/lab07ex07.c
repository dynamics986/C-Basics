/** Happy Numbers */

#include <stdio.h>

int system(int num){
    int digitSum = 0; // To store the sum of digits of "num"
    int digit = 0;

    while (num > 0) {         
        digit = num % 10;
        digitSum += digit*digit;   // Add the last digit of num to digitSum
        num = num / 10;         // Remove the last digit from num
    }
    return digitSum;
}

int main(void) {

    int num;
    printf("x? ");
    scanf("%d", &num);
    char endloop = 0;

    while(num != 1 && num != 4){
        num = system(num);
        printf("=> %d ", num);
        endloop = 1;

        if (num == 1)
            break;
        
        else if (num == 4)
            break;
    } 
    if (endloop == 1)
        printf("\n");

    if (num == 1){
        printf("Happy Number! :)");
    }
        
    else if (num == 4){
        printf("Unhappy Number! :(");
    }

    return 0;
}

