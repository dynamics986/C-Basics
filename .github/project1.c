/** output test */
#include <stdio.h>

int res(int a){
    static int s = 2;
    s+=s;
    return s;
}

void foo(int i,int sum){
    sum *= i;
    i -= 2;
}

void bar(char *s, int i){
    printf(s,i);
    i--;
    s[1]=i;
}

int main(void) {
    /** Key Word 'static' */
    // printf("%d\n",res(res(2)));

    /** Pass by Value */
    // int i, sum = 2;
    // for (i = 6 ; i > 1 ; i -= 2)
    //     foo(i,sum);
    // printf("%d\n",sum);
    // printf("%d\n",i);

    /** Function and Pointer */
    char s[] = "%d\n";
    int i1 =100;
    bar(s,i1);
    bar(s,i1);

    /** Consider overall situation */
    // int a = 3.1 + 2;	   	
    // double b = 4;
    int x = 5;
    printf("%d\n",x /*/ 2);printf("EndoftheWorld"*/);
    // printf("%d %.1f\n",a,b);

    /** limited calculation accuracy. */
    double area = 3.14*1.5*1.5;
    printf("%.2f\n", area);
    printf("%.2f\n", 7.065);
    
    /** Logic operation Overflow */
    // int A[6]={1,2,3,4,5,6};
    // int i2 = 7;
    // if (i2 < 6 || printf("Hello\n"))
    //     printf("%d",A[i2]);

    /** String Overflow */
    // char a[4]={'t','e','s','t'};
    // char b[]= "This is secret!\n";
    // printf("%s",a);

    /** Operator Precedence */
    int d = 67, b = 0;
    // printf("%d\n",d&&&b);// &b is not NULL in most cases
    // printf("%d\n", d-!-b);
    return 0;
}
