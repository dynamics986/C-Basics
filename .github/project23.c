#include <stdio.h>
#include <stdint.h>

uint64_t seed = 1002 ; // seed must start with a nonzero value

uint64_t xorshift64star( void ){
    // >>, <<, and ^ are bitwise operator
    seed ^= seed >> 12 ; // >> - shift to right
    seed ^= seed << 25 ; // << - shift to left
    seed ^= seed >> 27 ; // ^ - XOR (exclusive OR)
    seed = seed * UINT64_C( 2685821657736338717 ) ;
    return seed ;
}

int main( void ){
    printf( "%d\n" , (int) ( xorshift64star() % 1000 ) );
    printf( "%d\n" , (int) ( xorshift64star() % 1000 ) );
    printf( "%d\n" , (int) ( xorshift64star() % 1000 ) );
    return 0 ;
}