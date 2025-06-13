#include <stdio.h>
int main(){
    double input1, input2;
    scanf("%lf%lf",&input1,&input2);
    double min1 = (input1 < input2) ? input1 : input2 ;
    printf("The min is %f\n", min1);
    double min2 = ( input1 < input2 ) * input1 \
    + ( 1 - ( input1 < input2 ) ) * input2 ;
    printf("The min is %f\n", min2);
    return 0;
}