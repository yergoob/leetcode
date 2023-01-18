// 36. Valid Sudoku
// Created by ear on 1/1/23.
//
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
bool valid(int i, bool** rows,bool** cols,bool** subbox,
           int row, int col, int whichbox){
   return (!rows[row][i]) && (!cols[col][i]) && (!subbox[whichbox][i]);
}
bool dfs(char** board, int size, bool** rows, bool** cols, bool** subbox){
    if(size == 9*9)
        return true;
    else{
        int i;
        bool ok = false;
        int row = size/9;
        int col = size%9;
        int whichbox = row/3*3 + col/3;
        if(board[row][col] == '.'){
            for(i = 1; i <=9; ++i){
                if(valid(i, rows, cols, subbox, row, col, whichbox)){
                    board[row][col] = i + '0';
                    rows[row][i] = true;
                    cols[col][i] = true;
                    subbox[whichbox][i] = true;
//                    for(int m = 0; m <= row; ++m) {
//                        for (int n = 0; n < 9; ++n) {
//                            printf("%c,", board[m][n]);
//                        }
//                        printf("\n");
//                    }
//                    printf("------------------------------------\n");
                    ok = dfs(board, size+1, rows, cols, subbox);
                    if(!ok){
                        rows[row][i] = false;
                        cols[col][i] = false;
                        subbox[whichbox][i] = false;
                        board[row][col] = '.';
                    }
                }
            }
        }else{
            ok = dfs(board, size+1, rows, cols, subbox);
        }
        return ok;
    }
}
void solveSudoku(char** board, int boardSize, int* boardColSize){
    bool **rows = malloc(sizeof(bool*)*9);
    bool **cols = malloc(sizeof(bool*)*9);
    bool **subbox = malloc(sizeof(bool*)*9);

    int i, j;
    for(i = 0; i < 9; ++i){
        rows[i] = malloc(sizeof(bool)*10);
        cols[i] = malloc(sizeof(bool)*10);
        subbox[i] = malloc(sizeof(bool)*10);
        memset(rows[i], false, sizeof(bool)*10);
        memset(cols[i], false, sizeof(bool)*10);
        memset(subbox[i], false, sizeof(bool)*10);
    }
    int number, whichbox;
    for(i = 0; i < 9; ++i){
        for(j = 0; j < 9; ++j){
            if(board[i][j] != '.'){
                number = board[i][j] - '0';
                whichbox = i/3*3 + j/3;
                rows[i][number] = true;
                cols[j][number] = true;
                subbox[whichbox][number] = true;
            }
        }
    }
    int size = 0;
    dfs(board, size, rows, cols, subbox);
}
int main(){
    int boardSize = 9;
    int boardColSize = 9;
    int i, j;
    char b[9][9] = {
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
    char** board = malloc(sizeof(char*)*9);
    for(i = 0; i < 9; ++i){
        board[i] = malloc(sizeof(char)*9);
    }
    for(i = 0; i < 9; ++i){
        for(j = 0; j < 9; ++j){
            board[i][j] = b[i][j];
        }
    }
    for(i = 0; i < 9; ++i){
        for(j = 0; j < 9; ++j){
            printf("%c,", board[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------------\n");
    solveSudoku(board, boardSize, &boardColSize);
    for(i = 0; i < 9; ++i){
        for(j = 0; j < 9; ++j){
            printf("%c,", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}