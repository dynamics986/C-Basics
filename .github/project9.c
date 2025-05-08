/** Pass data by value or reference in C */
#include <stdio.h>

void studyHard(double newGPAs[],int arraySize){
	    newGPAs[0] = 4.0;
	    newGPAs[1] = 4.0;
}

void WorkHard(double newGPA){
    newGPA= 4.0;
}

int main (void) {

    double GPAs[2];
    GPAs[0] = 1.0;
    GPAs[1] = 1.5;
    studyHard(GPAs,2);
    printf("After study hard, GPAs[0] = %f\n",GPAs[0]);
    printf("After study hard, GPAs[1] = %f\n",GPAs[1]); // GPAs be changed

    double GPA = 1.0;
    WorkHard(GPA); 
    printf("After study hard, GPA = %f\n",GPA); //GPA will not be changed

    return 0;
}
