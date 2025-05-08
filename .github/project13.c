#include <stdio.h>

int main( void ){
    FILE * fptr ;
    int count = 0 ;
    fptr = fopen( "data.txt" , "r" ); // read-only (omit check NULL)
    while ( fgetc( fptr ) != EOF )
        count++ ;
    fclose( fptr ); // close file
    printf( "Number of bytes = %d\n", count );
    return 0 ;
}
