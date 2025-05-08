/** Print Calendar */
#include <stdio.h>

int main (){
    int start, days;
    scanf("%d %d",&start, &days);
    printf("Su Mo Tu We Th Fr Sa\n");

    int pointer=1;
    for (int i=0 ; pointer <= days ; i++){
        for (int j=0 ; j<7 && pointer <= days ; j++){
            if (i==0 && j<start){
                printf("   ");
            }
            else {
                printf("%2d ",pointer++);
            }
        }
        printf("\n");
    }

    return 0;
}