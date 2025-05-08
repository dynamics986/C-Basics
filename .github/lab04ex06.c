/** Useful! Integer Digit processing */ 
#include <stdio.h>

int main(void) {
	// 1. User input
	int phone;
	printf("Input phone number: ");
	scanf("%d", &phone);

	// 2. Phone number validation
    int digit[8];
	int decimal = 1;
	for (int i = 0; i < 8; i++){
		
		digit[7-i]=phone / decimal %10;
		decimal *= 10;
	}
    
	if (digit[0]<2||phone<10000000||phone>99999999)
	{
		printf("Invalid phone number");
		return 0;
	}
	// 3. Count the number of occurrences of digits
	// TO BE COMPLETED
	int occurs[10] = {0};	// array for storing the frequencies
	// HINT 1:
	// The occurrence of digit 0 can be stored in occurrences[0],
	// and the occurrence of digit 9 can be stored in occurrences[9].
	// HINT 2:
	//   printf("%d\n", phone / 10000000 % 10);	
	// can print out the first digit of the phone number
	int i;
    for (i=0;i<8;i++){
        occurs[digit[i]]=1;
    }
	// 4. Find the number of unique digits
	int unique = 0;
	for (int j=0;j<10;j++){
        unique += occurs[j];
    }
	// we can assign the index by put something into []
	// 5. Print out the results
	printf("There are %d unique digit(s).", unique);

	return 0;
}