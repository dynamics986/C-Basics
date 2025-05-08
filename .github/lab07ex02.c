/** use nested loop to print a Christmas tree */ 

#include <stdio.h>
int main(void) {
    int N;
    printf("Rows (2-20)? ");
    scanf("%d", &N);
    int i,j;
    for (i=0;i<N;i++){
        for (j=0;j<=N-i-2;j++){
            printf(".");
        }
        for (j=0;j<=2*i;j++){
            printf("*");
        }
        for (j=0;j<=N-i-2;j++){
            printf(".");
        }
        printf("\n");
    }
    return 0;
}