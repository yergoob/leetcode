//  39. 组合总和
// Created by ear on 1/5/23.
//
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#define MAXCOLSIZE  40
#define MAXRETSIZE  150
void copy(int* from, int** to, int* ret_size, int len){

    to[*ret_size] = malloc(sizeof(int) * len);
    for(int i = 0; i < len; ++i){
        to[*ret_size][i] = from[i];
    }
    ++(*ret_size);
}
void dfs(int* c, int c_size,
         int start, int target,
         int *temp, int len,
         int** ret, int* ret_size, int* ret_col_size){
    int i;

    if(target < 0){
        return;
    }else if(target == 0){
        ret_col_size[*ret_size] = len;
        copy(temp, ret, ret_size, len);
        return;
    }else{
        for(i = start; i < c_size; ++i){
            temp[len] = c[i];
            dfs(c, c_size, i, target-c[i], temp, len+1, ret, ret_size, ret_col_size);
        }
    }
 }
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int** ret = malloc(sizeof(int*)*MAXRETSIZE);
    int* temp = malloc(sizeof(int)*MAXCOLSIZE);

    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * MAXRETSIZE);
    int len = 0;

    dfs(candidates, candidatesSize, 0, target, temp, len, ret, returnSize, *returnColumnSizes);

    return ret;
}
int main(){
    int i, j;
    int c[] = {2,3,5};
    int target = 8;
    int *candidates = malloc(sizeof(int) * MAXCOLSIZE);
    int* returnColumnSizes; 
    int returnSize;

    for(i = 0; i < 3; ++i){
        candidates[i] = c[i];
    }
    int** ret = combinationSum(candidates, 3, target, &returnSize, &returnColumnSizes);

    for(i = 0; i < returnSize; ++i){
        for(j = 0; j < returnColumnSizes[i]; ++j){
            printf("%d,", ret[i][j]);
        }
        printf("\n");
    }
}