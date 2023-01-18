//0034的不够精简，想写一个精简版本的
// Created by ear on 12/31/22.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void insert_index(int* ret, int x){
    if((ret[0] == -1) || (ret[1] == -1)){
        ret[0] = x;
        ret[1] = x;
    }else{
        if(x < ret[0])
            ret[0] = x;
        else if(x > ret[1])
            ret[1] = x;
    }
}
void find(int* nums, int l, int r, int target, int* ret){
    int mid;
    if(l > r)
        return;

    mid = (l+r)/2;
    if(target == nums[mid])
        insert_index(ret, mid);

    if((l <= mid-1) && (target <= nums[mid-1]))
        find(nums, l, mid-1, target, ret);
    if((r >= mid+1) && (target >= nums[mid+1]))
        find(nums, mid+1, r, target, ret);
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){

    int *ret = malloc(sizeof(int)*2);
    memset(ret, -1, sizeof(int)*2);

    find(nums, 0, numsSize-1, target, ret);

    *returnSize = 2;
    return ret;
}
int main(){
    int nums[] = {3,3,3};
    int numsSize = sizeof(nums)/sizeof(*nums);
    int target = 3;
    int returnSize;
    int * ret = searchRange(nums, numsSize,target, &returnSize);

    putchar('[');
    for(int i = 0; i < returnSize; ++i){
        printf("%d",  ret[i]);
        if(i == 0)
            putchar(',');
    }
    printf("]\n");
}
