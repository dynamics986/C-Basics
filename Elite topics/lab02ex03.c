/** Minesweeper Map */
#include <stdio.h>
#define MAX_ROW 600
#define MAX_COLUMN 600

void fillCell(char map[][MAX_COLUMN],int row,int column,int i,int j){
    int X[8]={-1,-1,-1,0,0,1,1,1};
    int Y[8]={-1,0,1,-1,1,-1,0,1};
    int r,c;
    map[i][j] = 48;
    for (int n=0;n<8;n++){
        r = i + X[n];
        c = j + Y[n];
        if (0<=r&&r<row && 0<=c&&c<column && map[r][c]=='*'){
            map[i][j]++;
        }
    }
}

int main(){
    int row,column;
    char map[MAX_ROW][MAX_COLUMN];
    scanf("%d %d",&row, &column);
    // input and restore it in an array
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            // if not \n
            scanf(" %c",&map[i][j]); 
            // need a space to consume whitespace input

    // //debug
    // for (int i=0;i<row;i++){
    //     for (int j=0;j<column;j++){
    //         printf("%c ",map[i][j]);
    //     }
    //     printf("\n");
    // }
    // //

    // calculate mine around "."
    for (int i=0;i<row;i++){
        for (int j=0;j<column;j++){
            if (map[i][j] == '.'){
                fillCell(map,row,column,i,j);
                // fill in the number
            }
        }
    }

    for (int i=0;i<row;i++){
        for (int j=0;j<column;j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
    return 0;

}