/** Find all prime numbers between M,N,
 *  and then print out their sum and count
 */

#include <stdio.h>

int main(){
    // input M,N
    int M, N;
    scanf("%d %d", &M, &N);

    // set range and for loop
    int i, j;
    int sum = 0, count = 0;
    for (i = M; i <= N; i++){
        int isPrime = 1;
        // decide whether prime number
        for (j = 2; j <= i - 1; j++){
            if (i % j == 0){
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            sum += i;
            count += 1;
        }
    }
    printf("%d %d\n", count, sum);

    return 0;
}