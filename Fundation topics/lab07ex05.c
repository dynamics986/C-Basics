/** print 2 trees with different patterns */

#include <stdio.h>

void PrintTree(int N) {
    int i,j;
    for (i=0;i<N;i++){
        for (j=0;j<=N-i-2;j++){
            printf(".");
        }
        for (j=0;j<=2*i;j++){
            if (j%2==0)
                printf("*");
            else 
                printf("@");
        }
        for (j=0;j<=N-i-2;j++){
            printf(".");
        }
        printf("\n");
    }
}


int main(void) {
    int N;
    printf("Rows (2-20)? ");
    scanf("%d", &N);
    
    PrintTree(N);
    PrintTree(N);
    
    return 0;
}