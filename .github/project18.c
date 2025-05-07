#include <stdio.h>

int main(){
    int board[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    printf("Test Part 1:\n");
    printf("- board = %p\n" , &(board) );
    printf("- board[0] = %p\n" , &(board[0]) );
    printf("- board[0][0] = %p\n" , &(board[0][0]) );
    printf("- board[1] = %p\n" , &(board[1]) );
    printf("- board[1][0] = %p\n" , &(board[1][0]) );
    printf("Test Part 2:\n");
    printf("- diff[0][1]-[0][0] = %d\n" , &(board[0][1]) - &(board[0][0]) );
    printf("- diff[1][0]-[0][0] = %d\n" , &(board[1][0]) - &(board[0][0]) );
    printf("- diff[1]-[0] = %d\n" , &(board[1]) - &(board[0]) );
    printf("Test Part 3 (char-based):\n");
    printf("- diff[0][1]-[0][0] = %d\n",(char*)&(board[0][1])-(char*)&(board[0][0]));
    printf("- diff[1][0]-[0][0] = %d\n",(char*)&(board[1][0])-(char*)&(board[0][0]));
    printf("- diff[1]-[0] = %d\n",(char*)&(board[1])-(char*)&(board[0]));
    return 0;
}