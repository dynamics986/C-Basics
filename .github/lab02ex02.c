/** Closest square */

#include <stdio.h>
#include <math.h>

int main(){
    // input
    int num;
    scanf("%d",&num);

    // whether square
    int squ = (int)sqrt(num);
    if (squ*squ == num )
        printf("%d\n",num);
    else {
        // if not, find closest square and print
        if ((num - squ*squ) > ((squ+1)*(squ+1)-num ))
            printf("%d\n",(squ+1)*(squ+1));
        else
            printf("%d\n", squ*squ );   
    }
    





    return 0;

}