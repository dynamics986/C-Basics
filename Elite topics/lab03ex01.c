/** N-order decreasing triangle recursion */
#include <stdio.h>

void recursion(int n){
    if (n == 1)
        printf("1\n");
    else if (n > 1){
        printf("%d,",n);
        recursion(n-1);
    }
}

int main (){
    int order;
    scanf("%d",&order);
    for (int i = order; i>0; i--)
        recursion(i);


    return 0;
}