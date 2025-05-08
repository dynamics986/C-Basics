/** Useful! compare and selecion questions */ 
#include <stdio.h>

int main(void) {
  
    int countVote[3]={0};
    int k,i;
    for (k=1;k<=10;k++){
        scanf("%d",&i);
        countVote[i-1] += 1;
        //pay attention to the index!
    //we can assign i to the index.
    }
   // printf("%d%d%d",countVote[0],countVote[1],countVote[2]);

    int max;
    if (countVote[0]>countVote[1]){
        if (countVote[0]>countVote[2])
            max = 1;
        else if (countVote[0]==countVote[2])
            max = 0;
        else max = 3;
    }
    
    if (countVote[0]==countVote[1]){
        if (countVote[0]>countVote[2])
           max = 0;
        else max = 3;
    } 
    
    if (countVote[0]<countVote[1]){
        if (countVote[1]>countVote[2])
            max = 2;
        else if (countVote[1]==countVote[2])
            max= 0;
        else max = 3;
    }
    if (max>0)
    printf("Congratulations! Candidate %d is the next committee chairman.\n", max);
    else printf("We cannot decide our committee chairman in this vote.\n");
  return 0;
}