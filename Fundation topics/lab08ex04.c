/** binary and Decimal conversion, really useful! */

#include <stdio.h>

int binaryToDecimal(int b) {
    int d = 0;
    int lastDigit = 0;
    int base = 1;
    
	while (b > 0){
        lastDigit = b % 10;
        d += base * lastDigit;
        base *= 2;
        b /= 10;
    }
    return d;
}

int decimalToBinary(int d) {
    int b = 0;
    int lastDigit = 0;
    int base = 1;
    
	while (d > 0){
        lastDigit = d % 2;
        b += base * lastDigit;
        base *= 10;
        d /= 2;
    }
    return b;
	

}

int main(void) {
    int b1, b2, d1, d2, diff_b, diff_d;
    // Read b1 and b2 from user, and start calculation
    printf("b1 and b2? ");
    scanf("%d %d", &b1, &b2);
    
    // Do NOT modify the following lines
    // NEVER EVER TOUCH THESE!
    d1 = binaryToDecimal(b1);
    d2 = binaryToDecimal(b2);
    printf("The numbers (in decimal) are %d and %d\n", d1, d2);
    diff_d = d1 - d2;
    diff_b = decimalToBinary(diff_d);
    printf("The difference is %d (decimal) or %d (binary)\n", diff_d, diff_b);
    return 0;
}