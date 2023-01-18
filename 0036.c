// 36. Valid Sudoku
// Created by ear on 1/1/23.
//  char a[] = "string"; // the compiler puts {'s','t','r','i','n','g', 0} onto STACK
//  char *a = "string"; // the compiler puts just the pointer onto STACK
//                    // and {'s','t','r','i','n','g',0} in static memory area
#include <stdio.h>
#include <stdbool.h>
//bool isValidSudoku(char** board, int boardSize, int* boardColSize){
bool isValidSudoku(char board[9][9], int boardSize, int* boardColSize){ // 哇塞，竟然要这样传递二维数组
    char row[9][9] = {{'\0'},{'\0'},{'\0'},
                     {'\0'},{'\0'},{'\0'},
                     {'\0'},{'\0'},{'\0'}};
    char col[9][9] = {{'\0'},{'\0'},{'\0'},
                     {'\0'},{'\0'},{'\0'},
                     {'\0'},{'\0'},{'\0'}};
    char subbox[9][9] = {{'\0'},{'\0'},{'\0'},
                       {'\0'},{'\0'},{'\0'},
                       {'\0'},{'\0'},{'\0'}};
    int i, j, number, which_subbox;
    for(i = 0; i < boardSize; ++i){
        for(j = 0; j < *boardColSize; ++j){
            if(board[i][j] != '.'){
                number = board[i][j] - '0' - 1;
                which_subbox = i/3*3 + j/3;
                if((row[i][number] == 1) || (col[j][number] == 1) || (subbox[which_subbox][number] == 1))
                    return false;
                else{
                    row[i][number] = 1;
                    col[j][number] = 1;
                    subbox[which_subbox][number] = 1;
                }
            }
        }
    }
    return true;
}
int main(){
    int boardSize = 9;
    int boardColSize = 9;
    char board[9][9] = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
  /*  // test board;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            printf("%c,", board[i][j]);
        }
        printf("\n");
    }*/
    bool ret = isValidSudoku(board, boardSize, &boardColSize);
    printf("%s\n", ret ? "true" : "false");
}