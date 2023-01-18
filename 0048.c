// 48. 旋转图像
// Created by ear on 1/16/23.
//
#include <stdio.h>
#include <stdlib.h>
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, temp;

    for(i = 0; i < matrixSize/2; ++i){
        for(j = 0; j < (matrixSize+1)/2; ++j){
            temp = matrix[i][j];
            // 等号右边的列就是等号左边的行， 等号右边的行就等于（matrixSize-1）减去等号左边的列
            // 上面的还可以这样理解， 等号左边的行就等于等号右边的列， 等号左边的列就等于（matrixSize-1）减去等号右边的行
            matrix[i][j] = matrix[matrixSize-1-j][i];
            matrix[matrixSize-1-j][i] = matrix[matrixSize-1-i][matrixSize-1-j];
            matrix[matrixSize-1-i][matrixSize-1-j] = matrix[j][matrixSize-1-i];
            matrix[j][matrixSize-1-i] = temp;
        }
    }
}
int main(){
    int matrixSize = 4;
    int matrixColS[] = {4,4,4,4};
    int* matrixColSize = &matrixColS;
    int m[4][4] = {{1,2,3,1},
                 {4,5,6,1},
                 {7,8,9,1},
                   {2,2,2,1}};
    /**
     *      m[0][1]->m[1][2]
     *      m[i][j]->m[j
     */
    int **matrix = malloc(sizeof(int*)*matrixSize);

    for(int i = 0; i < matrixSize; ++i)
        matrix[i] = &m[i];
//    for(int i = 0; i < matrixSize; ++i){
//        matrix[i] = malloc(sizeof(int)*(matrixColSize[i]));
//        for(int j = 0; j < matrixColSize[i]; ++j)
//            matrix[i][j] = m[i][j];
//    }

    rotate(matrix, matrixSize, matrixColSize);
    for(int i = 0; i < matrixSize; ++i){
        for(int j = 0; j < matrixColSize[i]; ++j){
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}