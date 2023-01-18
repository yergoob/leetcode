//34. Find First and Last Position of Element in Sorted Array
// Created by ear on 12/31/22.
//
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define BIG 1
#define SMALL 0
void find(int* nums, int l, int r, int target, int* ret, int* returnSize, int flag){
    int mid;

    while(l <= r){
        mid = (r+l)/2;
        if(target < nums[mid]){
            r = mid-1;
        }else if(target > nums[mid]){
            l = mid+1;
        }else{
            if(*returnSize == 1){
                if(ret[0] > mid){
                    ret[1] = ret[0];
                    ret[0] = mid;
                    (*returnSize)++;
                }else
                    ret[(*returnSize)++] = mid;
            }else{
                if(flag == BIG)
                    ret[1] = mid;
                else
                    ret[0] = mid;
            }
            if(flag == BIG){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
    }
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int l = 0, r = numsSize-1, mid;

    int *ret = malloc(sizeof(int)*2);
    memset(ret, -1, sizeof(int)*2);

    *returnSize = 0;
    while(l <= r){
        mid = (l+r)/2;
        if(target < nums[mid])
            r = mid-1;
        else if(target > nums[mid])
            l = mid+1;
        else{
            ret[(*returnSize)++] = mid;
            if((mid+1) <= r){
                find(nums,mid+1, r, target, ret, returnSize,BIG);
            }
            if((mid-1) >= l){
                find(nums,l, mid-1, target, ret, returnSize,SMALL);
            }
            break;
        }
    }
    if(*returnSize == 0)
        *returnSize = 2;
    if(*returnSize == 1){
        (*returnSize)++;
        ret[1] = ret[0];
    }
    return ret;
}
int main(){
    int nums[] = {5,7,7,8,8,10};
    int numsSize = sizeof(nums)/sizeof(*nums);
    int target = 8;
    int returnSize;
    int * ret = searchRange(nums, numsSize,target, &returnSize);
    printf("returnSize==%d, [%d, %d]\n", returnSize, ret[0], ret[1]);
}