/** 'fgets()' and 'fscanf()' */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
//Create two char array inputArray1 and inputArray2 
//of size 20 and set all elements to 0
	char inputArray1[20]={0};
	char inputArray2[20]={0};
// Open the file data.txt
	// FILE *fp;
	// fp = fopen("data.txt","r");

// Use fgets() to get a string from user into inputArray1
// Print the 20 elements of inputArray1 one by one, as a number (i.e. ASCII code)
// Print inputArray1 to the screen, as a string
	fgets(inputArray1,20,stdin);
	// will continue when meet space
	for (int i=0;i<20;i++){
		printf("%d ",inputArray1[i]);
	}
	printf("\n");
	for (int i=0;i<20;i++){
		printf("%c",inputArray1[i]);
	}
	
	printf("strlen1 = %d\n",(int)strlen(inputArray1));
// rewind(fp); no need
// Use fscanf() to get a string from user into inputArray2
// Print the 20 elements of inputArray2 one by one, as a number (i.e. ASCII code)
// Print inputArray2 to the screen, as a string
	fscanf(stdin,"%19s",inputArray2);
	// will stop when meet space
	for (int j=0;j<20;j++){
		printf("%d ",inputArray2[j]);
	}

	printf("\n");

	for (int j=0;j<20;j++){
		printf("%c",inputArray2[j]);
	}
	printf("\n");
	
	printf("strlen2 = %d\n",(int)strlen(inputArray2));
	// Close the file
	// fclose(fp);

	return 0;
}
 