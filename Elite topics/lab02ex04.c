/** RGB to HSV Color Conversion */
#include <stdio.h>


int main (){
    int RGB[3],HSV[3];
    scanf("%d %d %d",&RGB[0],&RGB[1],&RGB[2]);
    double r = RGB[0]/255.0;
    double g = RGB[1]/255.0;
    double b = RGB[2]/255.0;
    // determine max and min
    double max = 0, min = 1;
    if(r>g){
        max = r;
        min = g;
    }
    else{
        max = g;
        min = r;
    }
    if (max < b)
        max = b;
    if (min > b)
        min = b;
    
    // V = max{r,g,b}
    double V = max;
    // calculate S
    double S;
    if (V == 0)
        S = 0;
    else {
        S = (V - min)/ V;
    }
    // calculate H
    double H;
    if (S == 0)
        H = 0;
    else if (max == r)
        H = (g-b)/(V-min);
    else if (max == g)
        H = 2.0 + (b-r)/(V-min);
    else if (max == b)
        H = 4.0 + (r-g)/(V-min);
    H *= 60.0;
    while (H < 0)
        H += 360;
    H /= 360.0;
    // print HSV as Float
    printf("H = %.3f\n",H);
    printf("S = %.3f\n",S);
    printf("V = %.3f\n",V);
    return 0;
}