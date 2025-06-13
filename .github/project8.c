/** pointer and array */
#include <stdio.h>

int main(){
    const int N = 5;
    int A[N][N];
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            A[i][j] = i+j;

    printf("Use array: \n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%3d", A[i][j]);
        printf("\n");
    }

    printf("Use Pointer: \n");
    int *pa = &A[0][0];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%3d", *(pa+N*i+j));
        printf("\n");
    }
    
    return 0;
}