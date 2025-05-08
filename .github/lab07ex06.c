/** Moving average of order K */

#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    int a[N];
    
    for (int i=0; i<N; i++)
        scanf("%d", &a[i]); 
    
    int sum = 0;
    double result = 0.0;
    for (int j=0; j<=N-K;j++){
        sum = 0;
        for (int k=0;k<=K-1;k++){
            sum += a[j+k];
        }
            
        result = (double)sum/K;
        printf("%.2f",result);
        if (j < N-K)
            printf(" ");
        
    }
    return 0;
}