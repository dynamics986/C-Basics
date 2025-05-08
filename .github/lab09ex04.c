/** Reading a txt file with many numbers
 * calculate variance without an array
 * The key idea is Var[X] = E[X2] – E[X]2
 */

#include<stdio.h>
#include<stdlib.h>


#include <stdio.h>
int main(){

//The user will input i and j to indicate the start and end of the sublist.
int start, end;
scanf("%d%d", &start, &end);
// Open the file, value.txt, using read mode.
    FILE *fp;
    fp = fopen("numbers.txt","r");
    if (fp == NULL) {
        printf("Cannot open file!\n");
        exit(1); // Terminate the program immediately
    }

// Initialize sum_of_square = 0, sum = 0, N = 0.
    int sum_of_square = 0;
    int sum = 0;
    int N = 0, n = 0;
    int store;
// Repeat the following steps, until no more numbers can be read from the file:
    while (n <= end){
// Read a number from the file.
    fscanf(fp,"%d", &store);
    
    n++;
// If it is not the [i, j]-th number, then continue.
    if( n < start || n > end)
        continue;

// Add the number to sum.
    sum += store;
// Add the number × number to sum_of_square.
    sum_of_square += store * store;
// Increase N by 1
    N++;
    }
    //printf("%d\n",sum_of_square);
    //printf("%d\n",sum);

// Calculate variance = sum_of_square / N – (sum / N)2
    double variance = (double)sum_of_square / N - ((double)sum / N)*((double)sum / N);
// Output variance up to 4 decimal places.
    printf("%.4f",variance);
// Close the file.
    fclose(fp);
    return 0;

}
