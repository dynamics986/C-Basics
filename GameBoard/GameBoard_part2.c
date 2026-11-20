/**
 * ENGG1110 24R1 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy a nd
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : FAN Sixing
 * Student ID    : 1155211001
 * Class/Section : A
 * Date          : 26/11/2024
 */

/****************************************/
/* Header File Declaration */
#include <stdio.h>
#include <stdlib.h>
/* NO other header files are allowed */
/****************************************/
/****************************************/
/* Given Global Variables and Definition */
#define H 6  // height
#define W 6  // width

char candies[] = {'*', '#', '@', '%'};
/* NO other global variables are allowed */
/****************************************/

/****************************************/

/* Part I Functions */
void initGameBoard(int board[][W], int board_sample[][W]);
void printGameBoard(int board[][W]);
int askForSwap(int board[][W]);
void swap(int board[][6], int row1, int col1, int row2, int col2) ;
int findAndRemoveMatch(int board[][W], int row, int col);
int isMatching(int board[6][6], int row, int col);
/* Part II Functions */
int initGameBoardFromFile(int board[][W], int stacks[]);
void applyGravity(int board[][W]);
int fillEmpty(int board[][W], int stacks[], int current, int numCandies);
int cascade(int board[][6], int stacks[], int current, int numCandies);
/* Functions Added by Student*/
int Validate1(int board[][W], int row, int col);
int Validate2(int board[][W], int row, int col);

/****************************************/
// Function Definitions/

/**
 * Main() will call this function in the beginning.
 * initGameBoard() load the game board with the pre-defined board_sample array
 * @param board The gameboard the game is using
 * @param board_sample The given game board sample values
 */
void initGameBoard(int board[][W], int board_sample[][W]) {
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      board[i][j] = candies[board_sample[i][j]];
    }
  }
  // Since we cannot use <string.h>
  // we have to copy it one by one
}

/**
 * [Part II]
 * Main() will call this function in the beginning.
 * initGameBoardFromFile will load the file "board.txt" to load two information:
 * (1) Game Board ; (2) Candy Stacks
 * If the file loading is unsuccessful, quit the program with the error message.
 * @param board The Game board the program is using.
 * @param stacks The stack array to store candies. It will be inititalized from the file.
 * @return The number of candies in the stack.
 */
int initGameBoardFromFile(int board[][W], int stacks[]) {
  int num;
  int row , col;
  int board_store[6][6];
  FILE *fp = fopen("board.txt","r");
  if(fp == NULL){
    printf("Failed to open board.txt!\n");
    exit(-1);
  }
  fscanf(fp,"%d %d",& row, &col );
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      fscanf(fp,"%d",& board_store[i][j]);
      board[i][j] = candies[board_store[i][j]];
    }
  }

  fscanf(fp,"%d",&num);
  if (num > 100)
    num = 100;
  
  for (int i = 0; i < num; i++){
    fscanf(fp,"%d", &stacks[i]);
  }

  fclose(fp);
  return num;
}

/**
 * Various functions will call this.
 * printGameBoard() will print the current game board in the specified format
 * @param board The game board the game is using
 */
void printGameBoard(int board[][W]) {
  printf("=====\n");
  printf("  | 0 | 1 | 2 | 3 | 4 | 5 |\n");

  for (int i = 0; i < 6; i++){
    printf(" %d| %c | %c | %c | %c | %c | %c |\n",i,board[i][0], board[i][1],board[i][2],board[i][3],board[i][4],board[i][5]);
  }
  
}

/**
 * Main() will call this function.
 * askForSwap() will perform the major game logic by (1) asking the users which candy to swap
 * (2)Validate whether the swapping can be done (3) Perform the swapping
 * @param board The game board the game is using.
 * @return 0 if the error is encountered (e.g. Coordinates out of bound);
 * 1 if swapping is successfully
 */
int askForSwap(int board[][W]) {
  int result = 1;
  int row, column;
  char direction;
  int target, start;
  int exception = 0;
  printf("Enter the coordinate (row, column) of the candy:");
  scanf("%d %d", &row, &column);
  
  if (Validate1 (board, row, column) == 0) {
    result = 0;
  }
  else {
    printf("Enter the direction to swap (U for Up, D for Down, L for Left, R for Right):");
    scanf(" %c", & direction); // a space to consume newline character

    if (direction == 'U'){
      if (Validate2 (board, row-1,column) == 1){
        swap (board,row,column,row-1,column);
        target = findAndRemoveMatch(board, row-1, column);
        start = findAndRemoveMatch(board, row, column);
        if (!( target || start)){
          // if () has difficult logic in it!
          printGameBoard(board);
          swap (board,row,column,row-1,column);
          printf("No Match found!\n");
          exception = 1;
        }
      }
        
      else result = 0;
    }
      
    else if (direction == 'D'){
      if (Validate2 (board, row+1,column) == 1){
        swap (board,row,column,row+1,column);
        target = findAndRemoveMatch(board, row+1, column);
        start = findAndRemoveMatch(board, row, column);
        if ( !( target || start )){
          printGameBoard(board);
          swap (board,row,column,row+1,column);
          printf("No Match found!\n");
          exception = 1;
        }
      }
        
      else result = 0;
    }
      
    else if (direction == 'L'){
      if (Validate2 (board,row,column-1) == 1){
        swap (board,row,column,row,column-1);
        target = findAndRemoveMatch(board, row, column-1);
        start = findAndRemoveMatch(board, row, column);
        if (!( target || start )){  
          printGameBoard(board);
          swap (board,row,column,row,column-1);
          printf("No Match found!\n");
          exception = 1;
        }
      }
        
      else result = 0;
    }
      
    else if (direction == 'R'){
      if (Validate2 (board,row,column+1) == 1){
        swap (board,row,column,row,column+1);
        target = findAndRemoveMatch(board, row, column+1);
        start = findAndRemoveMatch(board, row, column);
        if (!( target || start )){
          printGameBoard(board);
          swap (board,row,column,row,column+1);
          printf("No Match found!\n");
          exception = 1;
        }
      }
       
      else result = 0;
    }
      
    else {
      printf("Wrong Direction Input.\n");
      result = 0;
    }
  }
  
  if (result == 1 && exception == 0){
      printGameBoard(board);
  }
  return result;
}

/**
 * Following 2 Functions Added by Student FAN Sixing
 * Valid Swapping Check
 * @param board the game board the game is using
 * @param row The row number of the given coordinate
 * @param col The column number of the given coordinate
 * @return 1 if there is a match in the board, 0 if there is not.
 */
int Validate1(int board[][W], int row, int col) {
  int result = 1;
  if (row > 5 || row < 0 || col > 5 || col < 0){
    printf("Coordinates Out of Bound.\n");
    result = 0;
  }
  else if (board[row][col] == 32){
    printf("Empty Cell Selected.\n");
    result = 0;
  }
  return result;
}

int Validate2(int board[][W], int row, int col) {
  int result = 1;
  if (row > 5 || row < 0 || col > 5 || col < 0){
    printf("Move Out of Bound.\n");
    result = 0;
  }
  else if (board[row][col] == 32){
    printf("Empty Cell Selected.\n");
    result = 0;
  }
  return result;
}


/**
 * Various functions will call this
 * swap() will perform value swapping of two cells,
 * with the given source and destination coordinates respectively.
 * @param board the game board the game is using
 * @param row1 The row number of the source cell
 * @param col1 The column number of the source cell
 * @param row2 The row number of the destination cell
 * @param col2 The column number of the destination cell
 */
void swap(int board[][6], int row1, int col1, int row2, int col2) {
  int temp;
  temp = board[row1][col1];
  board[row1][col1] = board[row2][col2];
  board[row2][col2] = temp;
}

/**
 * Various functions will call this.
 * findAndRemoveMatch() will find possible matches at the given coordinates (row,col)
 * for all four directions (Up, Down, Left, Right).
 * If found, turn the cell to ASCII 32 (' ').
 *
 * @param board The game board the game is using
 * @param row The row number of the given coordinate
 * @param col The column number of the given coordinate
 * @return 1 if there is a match in the board, 0 if there is not.
 */
int findAndRemoveMatch(int board[][W], int row, int col) {
  char candy = board[row][col];
  int result = 0;

  if (candy != 32){
    int left = 1, right = 1;
    while (board[row][col-left] == candy && col-left>=0){
      left++;
    }
    while (board[row][col+right] == candy && col+right<=5){
      right++;
    }
    if (right+left>3 ){
      result = 1;
      for (int i = col-left+1 ;i <= col+right-1 ;i++){
        // copy, paste and edit will easily case mistakes!
        board[row][i] = ' ';
      }
      printf("Horizontal Match found at row %d!\n", row);
    }

    int up = 1, down = 1;
    while (board[row-up][col] == candy && row-up>=0 ){
      up++;
    }
    while (board[row+down][col] == candy&& row+down<=5){
      down++;
    }
    if (down+up>3){
      result = 1;
      for (int i = row-up+1 ;i <= row+down-1 ;i++){
        board[i][col] = ' ';
      }
      printf("Vertical Match found at column %d!\n", col);
    }
  }
  
  return result;
}

/**
 * Main() function will call this.
 * isGameOver() is to check whether there exists a game over situation, i.e.
 * no more match can be made under the current board scenerio.
 *
 * @param board The game board the game is using.
 * @return 1 if it is game over; 0 if it isn't.
 */
int isGameOver(int board[][W]) {
  // good strategy is to swap each candy with its right / bottom neighbour 
  // really smart!
  int result = 1;
  int row, column;
  char direction;
  for (row = 0; row < H-1; row++){
    for (column = 0;column < W; column ++){
      swap (board,row,column,row+1,column);
        if (isMatching(board,row,column) || isMatching(board,row+1,column) ){
          result = 0;
          swap (board,row,column,row+1,column);
          break;
        }
      swap (board,row,column,row+1,column);
    }
  }

  for (row = 0; row < H; row++){
    for (column = 0;column < W-1; column ++){
      swap (board,row,column,row,column+1);
        if (isMatching(board,row,column) || isMatching(board,row,column+1) ){
          result = 0;
          swap (board,row,column,row,column+1);
          break;
        }
      swap (board,row,column,row,column+1);
    }
  }

  return result;
}

/**
 * isGameOver() will call this function.
 * isMatching will check if there is at least 1 match-three at the given coordinate (row,col)
 * for four directions (Top,Down,Left,Right).
 * @param board The game board the game is using.
 * @param row The row number of the target cell
 * @param col The column number of the target cell
 * @return 1 if there is at least 1 match in any direction; 0 if there is not.
 */
int isMatching(int board[6][6], int row, int col) {
  int result = 0;
  char candy = board[row][col];

  int left = 1, right = 1;
  if (board[row][col]!=32){ // check non-empty cells
    while (board[row][col-left] == candy && col-left>=0){
      left++;
    }
    while (board[row][col+right] == candy && col+right<=5){
      right++;
    }
    if (right+left>3){
      result = 1;
    }

    int up = 1, down = 1;
    while (board[row-up][col] == candy && row-up>=0){
      up++;
    }
    while (board[row+down][col] == candy && row+down<=5){
      down++;
    }
    if (down+up>3){
      result = 1;
    }
  }

  return result;  
}

/**
 * [Part II]
 * askForSwap() and cascade() will call this function
 * applyGravity() will scan the all columns from left to right, and
 * if there are empty cells, it will move down the candy. Lastly, print the
 * gameboard.
 * @param board The game board the game is using
 */
void applyGravity(int board[][W]) {
  // int times;
  // for (int col = 0; col < 6; col++){
  //   times = 0;
  //   for (int row = 5; row > 0; row--){
  //     while (board[row][col]==32 && times<6){
  //       for (int k = row; k > 0; k--){
  //         board[k][col] = board[k-1][col];
  //       }
  //       board[0][col] = ' ';
  //       //printf("board[%d][%d] = %d\n",row,col,board[row][col]);
  //       times++;
  //     }
  //   }
  // }
  for (int col=0;col<6;col++){
    int emptyRow = 5;

    for (int row = 5; row >= 0; row--){
      if (board[row][col]!= 32){
        board[emptyRow][col] = board[row][col];
        if (emptyRow != row){
          board[row][col] = ' ';
        }
        emptyRow--;
      }
    }
  }
  printGameBoard(board);
}

/**
 * [Part II]
 * askForSwap() and cascade() will call this.
 * fillEmpty() will scan the columns from left to right. If there are empty cells,
 * it will fill them with candies got from the stacks, in bottom-to-top manner. Lastly,
 * print the gameboard.
 * @param board the game board the game is using
 * @param stacks the 1D array containing the candies
 * @param current the counter of the next candy location in stacks array
 * @param numCandies the total number of candies in the stacks
 * @return the updated current value, i.e. the updated counter pointing to the next
 * available candy
 */
int fillEmpty(int board[][W], int stacks[], int current, int numCandies) {
  int result = current;
  // int emptySpace = 0;
  // for (int col = 0; col < 6; col++){
  //   for (int row = 5; row >= 0; row--){ // cover all cells
  //     if (board[row][col]==32){
  //       emptySpace++;
  //     }
  //   }
  // }

  // if (result + emptySpace >= numCandies){
  //   printf("No more candies available.\n");
  //   printf("Process finished with exit code -1\n");
  //   exit(-1);
  // }

  // for (int col = 0; col < 6; col++){
  //   for (int row = 5; row >= 0; row--){ // cover all cells
  //     if (board[row][col]==32){
  //       board[row][col] = candies[stacks[result]];
  //       //printf("[%c]",board[row][col]);
  //       result++;
  //     }
  //   }
  // }

  for (int col = 0; col < 6; col++){
    for (int row = 5; row >= 0; row--){ // cover all cells
      if (result > numCandies){
        printf("No more candies available.\n");
        exit(-1);
      }

      if (board[row][col]==32){
        board[row][col] = candies[stacks[result]];
        result++;
      }
    }
  }

  printGameBoard(board);
  return result;
}

/**
 * [Part II]
 * main() function will call this
 * cascade() will continously check the board to see if there is any matches
 * and perform removal until no further matches can be found.
 * First, you can apply the gravity and fill in the empty cells.
 * Then, for each cells on the board and if it is not empty, try to call
 * findAndRemoveMatch() to remove matches if any. If there is a match,
 * print the specified message.
 * Remember to collect the return value of current in fillEmpty() such that
 * you return to the main function to update the variable.
 * @param board the game board the game is using
 * @param stacks the 1D array containing the candies
 * @param current the counter of the next candy location in stacks array
 * @param numCandies the total number of candies in the stacks
 * @return the updated current value, i.e. the updated counter pointing to the next
 * available candy
 */
int cascade(int board[][6], int stacks[], int current, int numCandies) {
  int jump = 1,temp = 0;
  int result = current;
  while (jump){
    jump = 0;
    applyGravity(board);
    result = fillEmpty(board,stacks,result,numCandies);
    //printGameBoard(board);
    for (int row = 0; row < H; row++){
      for (int column = 0; column < W; column++){
        if (board[row][column] == 32){
          continue;
        }
        temp = findAndRemoveMatch(board,row,column);
        if (temp == 1){
          jump = 1;
        }
      }
    }

    if (jump){
      printf("Cascade Matches found!\n");
    }
  }

  return result;
}
/* Main Function */
/**
 * The main function will hold the game loop and hold the game logic.
 * main() will call various functions to accompolish various tasks such as
 * initializing the game board, asking for Input, and etc.
 * It will hold an infinite loop to repeatly hold the game. If it is a game over status,
 * i.e. isGameOver() returns one (1), then it will break out of the loop and the program
 * finishes.
 *
 * @return 0
 */
int main(void) {
 // This is the variable holding a sample board value
  int board_sample[6][6] = {
    {1,3,2,0,1,0},
    {2,2,0,1,1,3},
    {1,3,3,2,3,0},
    {3,0,2,1,0,2},
    {1,0,2,3,3,2},
    {3,2,1,0,3,3}
  };


 int board[H][W] = {0}; // The game board, initialized to 0
 int stacks[100] = {0}; // Stacks array containing candy, Maximum capacity 100
 int numCandies = 0; // Number of candies in the stacks
 int current = 0; // the counter pointing to the next available candy
// You may declare more variables if needed.


 // 1. First, you may initialize the board first
 // For part 1, you may use initGameBoard() while for part 2, initGameBoardFromFile()
  numCandies = initGameBoardFromFile(board,stacks);
  
 // Then, you may hold a loop to keep the game running
  while(isGameOver(board)==0){
    printf("=====\n");
    printf("New Round:\n");
    printGameBoard(board);
    if(askForSwap(board)==0)
      printf("Please try again.\n");
    else {
      current = cascade(board,stacks,current,numCandies);
    }
      
  }
  printGameBoard(board);
  printf("Game Over! No more possible moves.\n");
  // printf for your reference
  //printf("=====\n");
  //printf("New Round:\n");

 // Print the board using printGameBoard()

  // Call askForSwap() to ask which candy to swap and perform swapping if successful.
  // If not, print error message, shown for your reference

  // printf("Please try again.\n");

  // Otherwise, continue the game logic by applying gravity and filling empty cells
  // For part II, you may replace the above two to cascade(), as cascade() will be
  // responsible to call at that moment.

 // Check if it is a game over status. If yes, print the message and break the loop
 // printf is left for your reference.

  // printf("Game Over! No more possible moves.\n");

// Hope you enjoy the game : )

 return 0;
}