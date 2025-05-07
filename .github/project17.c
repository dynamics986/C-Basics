#include <stdio.h>

int main( void ){
    char str[ 100 ];
    int i = 1 ;
    while ( scanf( "%s" , str ) > 0 ){
        printf( "Word %d: [%s]\n" , i , str );
        i++ ;
    }
    
    return 0 ;
}