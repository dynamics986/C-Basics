/** calculate the gcd and lcm */

#include <stdio.h>

int gcd(int x, int y) 
{
    while (y != 0) {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

int lcm(int x, int y) 
{
    int result= (x * y) / gcd(x,y);
    return result;
}

int main(void)
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int Gcd = gcd( gcd( gcd(a, b), c), d);
    int Lcm = lcm( lcm( lcm(a, b), c), d);
    printf("GCD is %d\n",Gcd);
    printf("LCM is %d\n",Lcm);
    return 0;
}