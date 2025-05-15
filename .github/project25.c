/** Test 'define' */
#include <stdio.h>

#define SWAP(A,B) { int tmp = A ; A = B ; B = tmp ; }
#define PRINT(X) printf( "%s = %d\n" , #X , X )

int main( void ){
    int a = 10 , b = 20 ;
    PRINT(a) ;
    PRINT(b) ;
    PRINT(a+b) ;
    printf( "%d %d\n" , a , b );
    SWAP( a , b );
    printf( "%d %d\n" , a , b );
    return 0;
}