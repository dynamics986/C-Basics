#include <stdio.h>
// ENGG1110 Midterm Code
int main(void){
    int nums[5];    //store the inputs
    int counts[5]={0};
    int mode;
    //complete the code
    int i=0,j=0;
    while (i<5){
        scanf("%d",&nums[i]);
        i++;
    }
    while (j<5){
        counts[nums[j]-1]++;
        j++;
    }
    
    int max = counts[0];
    mode = 1;
    int k=1;
    while(k<5){
        if (counts[k]>max){
            max = counts[k];
            mode = k+1;
        }
        k++;
    }

    //given code below
    printf("Input: %d %d %d %d %d\n",nums[0],nums[1],nums[2],nums[3],nums[4]);
    printf("---\n");
    printf("Index: 1 2 3 4 5\n");
    printf("Count: %d %d %d %d %d\n", counts[0],counts[1],counts[2],counts[3],counts[4]);
    printf("Mode: %d\n",mode);

    return 0;
}