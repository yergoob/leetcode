// 46. 全排列
// Created by ear on 1/13/23.
//
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void copy(int* from, int** to, int to_i, int len){
    to[to_i] = malloc(sizeof(int)*len);
    for(int i = 0; i < len; ++i)
        to[to_i][i] = from[i];
}
void dfs(int* nums, int numsSize, int *stack, int top, bool* used, int** ret, int* count, int* return_col_sizes){
    if(top == numsSize){
        copy(stack, ret, *count, top);
        return_col_sizes[*count] = top;
        ++(*count);
        return;
    }
    int i;
    for(i = 0; i < numsSize; ++i){
        if(used[i])
            continue;
        stack[top] = nums[i];
        used[i] = true;
        dfs(nums, numsSize, stack, top+1, used, ret, count, return_col_sizes);
        used[i] = false;
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize == 0){
        return NULL;
    }
    int i, ret_size;
    for(i = numsSize-1, ret_size = numsSize; i > 1; --i)
        ret_size *= i;

    int** ret = malloc(sizeof(int*)*ret_size);
    for(i = 0; i < ret_size; ++i)
        ret[i] = malloc(sizeof(int*)*numsSize);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int)*ret_size);

    int *stack = malloc(sizeof(int)*numsSize);int top = 0;
    bool *used = malloc(sizeof(bool)*numsSize);
    memset(used, false, sizeof(bool)*numsSize);

    dfs(nums, numsSize, stack, top, used, ret, returnSize, *returnColumnSizes);

    return ret;
}
int main(){
    int n[] = {1,2,3};
    int *nums = &n[0];
    int size = sizeof(n)/sizeof(*n);
    int returnSize, *returnColumnSizes;
    int** ret = permute(nums, size, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; ++i){
        for(int j = 0; j < returnColumnSizes[i]; ++j)
            printf("%d,", ret[i][j]);
        printf("\n");
    }
    return 0;
}