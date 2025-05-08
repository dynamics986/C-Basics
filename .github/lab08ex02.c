/** print a circle */

#include <stdio.h>
#include <math.h>

void PrintCircle (int radius){
    int i, j;
    double centerX, centerY;
    centerX = centerY = radius;
    for (i=0;i<=2*radius-1;i++){
        for (j=0;j<=2*radius-1;j++){
            double posX = i + 0.5;
            double posY = j + 0.5;
            double distance = sqrt( pow(posX-centerX, 2) + pow(posY-centerY, 2) );
            if (distance > radius)
                printf("-");
            else 
                printf("@");
            
            
        }
        printf("\n");
    }
}

int main(void) {
    // DO NOT CHANGE THE MAIN FUNCTION

    int radius;    // DON'T TOUCH THIS!
    
    printf("Radius? ");    // DON'T TOUCH THIS!
    scanf("%d", &radius);    // DON'T TOUCH THIS!
    PrintCircle(radius);     // DON'T TOUCH THIS!
    return 0;     // DON'T TOUCH THIS!
} 