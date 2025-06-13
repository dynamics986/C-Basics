#include <stdio.h>
#include <time.h>

/* Find out the biggest even number in an array */
int BigEven(int test[],int n){
    int result = 0;
    for (int i=0; i<n; i++){
        if (test[i]>result && test[i]%2 == 0){
            result = test[i];
            // printf("----test = %d-----\n",test[i]);
            // printf("----result = %d-----\n",result);
        }
    }
    return result;
}

int main(){
    int casenum;
    scanf("%d", &casenum);

    int arraysize;
    // clock_t start = clock();
    for (int i=0; i<casenum; i++){
        scanf(" %d",&arraysize);
        // printf("arraysize= %d",arraysize);
        int array[arraysize];
        for (int j=0; j<arraysize; j++){
            scanf(" %d",&array[j]);
            // printf("---%d",array[j]);
        }
        printf("%d\n",BigEven(array,arraysize));
    }
    // clock_t end = clock();
    // double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    // printf("Time taken for the loop: %f seconds\n", time_taken);
    return 0;
}