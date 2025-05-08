/** calculate the roots quadratic equation */ 

#include <stdio.h>
#include <math.h>
int main(void)
{
    int A,B,C;
    printf("Input A, B and C: ");
    scanf("%d %d %d",&A,&B,&C);
    int D ;
    double x1, x2;
    D = B*B - 4*A*C;
    printf("D = %d\n", D);
    if(D>0){
        x1 = (-B + sqrt(D))/(2*A);
        x2 = (-B - sqrt(D))/(2*A);
        if (x1 < x2){
            double tep;
            tep = x1;
            x1 = x2;
            x2 = tep;
        }
        printf("The two roots are %.2f and %.2f\n", x1, x2);
    }
    if (D==0){
        x1 = -B/(2.0*A);
        printf("The double root is %.2f\n", x1);
    }
    if (D<0){
        printf("No real roots\n");
    }
    return 0;
}