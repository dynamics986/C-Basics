/** Test Alien Number System */
#include <stdio.h>

int main (){
    int decimal, num;
    scanf("%d %d",&decimal, &num);
    // for loop to search the base
    // while loop to calculate alien number
    int pro,digit,base,result;
    int i;
    for ( i = 2;i < decimal; i++){
        pro = num;
        result = 0;
        base = 1;
        while (pro != 0){
            digit = pro % 10;
            result += base * digit;
            base *= i;
            pro /= 10;
        }
        if (result == decimal){
            break;
        }
    }
    
    if (i == decimal){
        printf("CHEATED\n");
    }
    else {
        printf("%d\n",i);
    }
    // print the result
    return 0;
}