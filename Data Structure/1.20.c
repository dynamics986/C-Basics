#include <stdio.h>
#include <ctype.h>
#include <time.h>
/* We stably delete all the digits and print remaining part */
int main(){
    int n;
    scanf("%d ", &n);
    char input[31];
    int len;
    clock_t start = clock();
    for (int i=0; i<n; i++){
        if (fgets(input,sizeof(input),stdin) != NULL){
            for (int j=0; j<31; j++){
                if (input[j] == '\0'){
                    break;
                }
                if (!isdigit(input[j]))
                    printf("%c",input[j]);
            }
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for the loop: %f seconds\n", time_taken);
    return 0;
}
