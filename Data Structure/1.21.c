#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool isPowerOfFive(int n){
    // if (n<1)
    //     return false;
    // while(n % 5 == 0){
    //     n /= 5;
    //     // printf("-----%d\n",n);
    // }
    // return (n==1);
    if (n < 1) 
        return false;
    double l = log(n) / log(5); // Calculate log base 5
    
    // Check if it's an integer
    return  (l - (int)l ) < 0.0000000000001; 
}

int main(){
    int n;
    scanf("%d",&n);
    int c;
    // clock_t start = clock();
    for (int i=0; i<n; i++){
        scanf(" %d",&c);
        printf("%s\n",isPowerOfFive(c) ? "True" : "False");
    }
    // clock_t end = clock();
    // double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    // printf("Time taken for the loop: %f seconds\n", time_taken);
    return 0;
}