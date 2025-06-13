/** Compute and print the row sums and column sums 
 *  of a given 2D array of integer elements
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int row, column;
    scanf("%d %d",&row, &column);
    int array[row][column];

    // 1. scan array elements, and
    for (int i = 0; i<row ; i++){
        for (int j = 0; j<column ; j++){
            scanf("%d", &array[i][j]);
        }
    }

    // 2. print the row and column sum.
    int rowsum[11]={0};
    for (int i = 0; i<row ; i++){
        for (int j = 0; j<column ; j++){
            rowsum[i] += array[i][j];
        }
    }

    int columnsum[11] ={0}; 
    for (int i = 0; i<column ; i++){
        for (int j = 0; j<row ; j++){
            columnsum[i] += array[j][i];
        }
    }

    printf("Row sums:\n");
    for (int i = 0; i< row ; i++){
        printf("%d\n", rowsum[i]);
    }

    printf("Column sums:\n");
    for (int i = 0; i< column ; i++){
        printf("%d", columnsum[i]);
        
        if (i < column -1)
            printf(" ");
    }
    return 0;
}