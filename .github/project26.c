#include <stdio.h>

#define myMax1(X,Y) X > Y ? X : Y
#define myMax2(X,Y) (X) > (Y) ? (X) : (Y) // better

int main(){
    int a = 10 , b = 20 , c = 30 ;
    int t1 = myMax1(a,b);
    int t2 = myMax2(a,myMax2(b,c));
    int t3 = myMax1(a,myMax1(b,c));
    printf("t1 = %d\n",t1);
    printf("t2 = %d\n",t2);
    printf("t3 = %d\n",t3);
    return 0 ;

}