/** Evil Numbers */

#include <stdio.h>

    void BinaryDigit(int num){
        int BinaryDigit = 0;
        int digit = 0;
        int result = num;

        while (num > 0) {         
            digit = num % 2;
            BinaryDigit += digit; // Add the last digit of num to digitSum
            num = num / 2;        // Remove the last digit from num
        }
        if (BinaryDigit % 2 == 0)
            printf("%d\n", result);
        }

    int main(void){
        int a,b;
        int i=0;
        scanf("%d %d",&a,&b);
// descending order for loop check part should be ">"
        for (i = b; i >= a; i--){ 
            BinaryDigit(i);
        }
        return 0;
    }