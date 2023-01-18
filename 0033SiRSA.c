// 折半查找
// Created by ear on 12/30/22.
//
#include <stdio.h>
int search(int* nums, int numsSize, int target){
    int l = 0;
    int r = numsSize-1;
    int mid;
    int ret = -1;

    while(l < r){
        mid = (r + l)/2;
        if(nums[l] <= nums[mid]){        //前一半 无悬崖（就是数突然变小））
            if(target < nums[l] || target > nums[mid]){       // target不在前一半
                l = mid+1;
            }else{       // target 在前一半中
                r = mid;
            }
        }else{                          // 前一半有悬崖，后一半是升序
            if(target < nums[mid] || target > nums[r]){    // target 不在后一半
                r = mid;
            }else{                      // target 有可能在后一半
                l = mid;
            }
        }
    }
    if(target == nums[l])
        ret = l;

    return ret;
}
int main(){
    int nums[] = {5,1,3};
    int ret;
    int target = 5;
    ret = search(nums, sizeof(nums)/sizeof(*nums), target);
    printf("%d\n", ret);
}