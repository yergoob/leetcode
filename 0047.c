// 47. 全排列 II
// Created by ear on 1/15/23.
//
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void q_sort(int* nums, int left, int right){
    int l = left, r = right;
    if(left < right){
        int temp = nums[l];
        while(l < r){
            while(l < r && nums[r] >= temp){--r;}
            if(l < r)
                nums[l++] = nums[r];
            while(l < r && nums[l] < temp){++l;}
            if(l < r)
                nums[r--] = nums[l];
        }
        nums[l] = temp;
        q_sort(nums, left, l-1);
        q_sort(nums, r+1, right);
    }
}
void copy(int* from, int** to, int len, int toWhere){
    to[toWhere] = malloc(sizeof(int)*len);
    for(int i = 0; i < len; ++i)
        to[toWhere][i] = from[i];
}
void dfs(int* nums, int numsSize, int* stack, int top, bool* used, int** ret, int* retSize, int* retColSizes){
    if(top == numsSize){
        copy(stack, ret, top, *retSize);
        retColSizes[*retSize] = top;
        ++(*retSize);
        return;
    }
    int last_pop;
    for(int i = 0; i < numsSize; ++i){
        if(!used[i]){
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;
            stack[top] = nums[i];
            used[i] = true;
            dfs(nums, numsSize, stack, top+1,  used, ret, retSize, retColSizes);
            used[i] = false;
        }
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    q_sort(nums, 0, numsSize-1);

    int i, size = numsSize;
    for(i = numsSize-1; i > 1; --i)
        size *= i;
    int** ret = malloc(sizeof(int*)*size);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int)*size);

    int* stack = malloc(sizeof(int)*numsSize); int top = 0;
    bool* used = malloc(sizeof(bool)*numsSize);
    memset(used, false, sizeof(bool)*numsSize);

    dfs(nums, numsSize, stack, top, used,  ret, returnSize, *returnColumnSizes);

    return ret;
}
int main(){
    int n[] = {1,1,2};
    int *nums = &n[0];
    int size = sizeof(n)/sizeof(*n);

    int returnSize;
    int *returnColumnSizes;
    int** ret = permuteUnique(nums, size, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; ++i){
        for(int j = 0; j < returnColumnSizes[i]; ++j){
            printf("%d,", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}