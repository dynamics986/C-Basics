/** Permutation with / without Repetion using Recursion */
#include <stdio.h>

void perm(int num_slots,char alphabets [],int a_len,char result [],int r_len){
    if ( num_slots == 0 ) {
        printf( "%s\n" , result );
        return ;
    }
    for ( int i = 0 ; i < a_len ; i++ ){ 
        result[r_len - num_slots] = alphabets[ i ];
        perm( num_slots - 1 , alphabets , a_len , result , r_len );
    }
}

void perm_without_repet( int num_slots , char alphabets [] , int a_len ,\
char result [] , int r_len ,int selected [] ){
    if ( num_slots == 0 ) // end?
        printf( "%s\n" , result );
    else {
        for ( int i = 0 ; i < a_len ; i++ ){
            if ( selected[ i ] == 0 ){
                selected[ i ] = 1 ;
                result[r_len - num_slots] = alphabets[ i ]; 
                perm_without_repet(num_slots - 1,alphabets,a_len,result,r_len,selected);
                selected[ i ] = 0 ; // common mistake: don't miss it!
            }
        }
    }
}

int main( void ){
    char alphabets [3] = { 'a' , 'b' , 'c' };
    char result [3] ; // 2 slots + '\0'
    result[2] = '\0' ;
    printf("Permutation with Repetition\n");
    perm(2,alphabets,3,result,2);
    int selected [3] = {0}; // length same as a_len
    printf("Permutation without Repetition\n");
    perm_without_repet(2,alphabets,3,result,2,selected);
}