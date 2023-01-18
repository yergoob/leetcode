// 40. 组合总和 II
// Created by ear on 1/7/23.
//
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#define MAXCOLSIZE  30
#define MAXRETSIZE  150
void q_sort(int *nums, int left, int right){
    int temp, l, r;

    l = left;
    r = right;
    if(l < r){
        temp = nums[l];
        while(l < r){
            while(l < r && nums[r] > temp){--r;}
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
void copy(int* from, int** to, int* count, int len){
    to[*count] = malloc(sizeof(int)*len);
    for(int i = 0; i < len; ++i){
        to[*count][i] = from[i];
    }
    (*count)++;
}
void dfs(int* nums, int nums_len, int start, int target,
         int* stack, int stack_len, int** ret, int* ret_size, int* ret_col_size){
    int i, j;

//    if(target < 0)
//        return;
//    else
    if(target == 0){
        ret_col_size[*ret_size] = stack_len;
        copy(stack, ret, ret_size, stack_len);
    }else{
        for(i = start; i < nums_len; ++i){
//            if(stack_len == 0 && i > 0 && nums[i] == nums[i-1])
//                continue;
//            if(start != i && i > 0 && nums[i] == nums[i-1])
//                continue;
            if(start != i && nums[i] == nums[i-1])
                continue;
            if((target-nums[i]) < 0)
                continue;
            stack[stack_len] = nums[i];
            dfs(nums, nums_len, i+1, target-nums[i], stack, stack_len+1, ret, ret_size, ret_col_size);
        }
    }
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){

    q_sort(candidates, 0, candidatesSize-1);
    for(int i = 0; i < candidatesSize; ++i){
        printf("%d,", candidates[i]);
    }
    printf("\n");
    int* stack = malloc(sizeof(int)*MAXCOLSIZE);int stack_len = 0;
    int** ret = malloc(sizeof(int*)*MAXRETSIZE);
    *returnColumnSizes = malloc(sizeof(int)*MAXRETSIZE);
    *returnSize = 0;

    dfs(candidates,candidatesSize,0,target,
        stack,stack_len,ret,returnSize,*returnColumnSizes);

    return ret;
}
int main(){
    int i, j;
    int c[] = {10,1,2,7,6,1,5};
//    int c[] = {2,5,2,1,2};
    int target = 8;
    int *candidates = malloc(sizeof(int) * MAXCOLSIZE);
    int cand_size  = sizeof(c)/sizeof(*c);
    int* returnColumnSizes;
    int returnSize;

    for(i = 0; i < cand_size; ++i){
        candidates[i] = c[i];
    }
    int** ret = combinationSum2(candidates, cand_size, target, &returnSize, &returnColumnSizes);

    for(i = 0; i < returnSize; ++i){
        for(j = 0; j < returnColumnSizes[i]; ++j){
            printf("%d,", ret[i][j]);
        }
        printf("\n");
    }
}