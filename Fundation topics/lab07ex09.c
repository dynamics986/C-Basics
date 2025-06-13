/** a program to draw a letter bridge */

#include <stdio.h>

int main(void) {
	// Hint 1: What is the character to be printed?
	//
	// height  1st character  'A'+?
	// ----------------------------------
	// 1       'A'            'A'+0
	// 5       'E'            'A'+4
	
	// Hint 2: How many characters in the first half of the row, for each row index i?
	// (e.g. height = 5)
	// i         characters  height-i
	// ----------------------------------
	// 0         EDCBA       height
	// 1         EDCB        height-1
	// .         EDC         .
    // height-2  ED          2
    // height-1  E           1
	
	// Hint 3:
	// How many dots in the middle of the row, for each row index i?
	//
	// i         # dots   
	// ----------------------------------
	// 0         0
	// 1         2
	// 2         4
    printf("Input bridge height: ");
    int row;
    scanf("%d", &row);

    for (int i=0;i<row;i++){
        for (int j=1;j<=row-i;j++){
            printf("%c", 'A'+row-j);
        }
        for (int l=0;l<2*i ;l++){
            printf(".");
        }

        for (int k=i;k<=row-1;k++){
            printf("%c", 'A'+k);
        }
        printf("\n");
    }
	return 0;
}