/** print all prime numbers within a and b descendingly */ 

#include <stdio.h>

int main(void) {
    int i, j, a, b, isPrime;
    printf("Input a and b: ");
    scanf("%d %d",&a, &b);

    for (i=b;i>=a;i--){
        isPrime = 1; 
        for (j=2;j<i;j++){
            if (i % j == 0)
            isPrime = 0;    
        }
        if (isPrime ==1)
        printf("%d ", i);   
    }

  
  return 0;
}