// 41. 缺失的第一个正数
// Created by ear on 1/7/23.
//
#include <stdlib.h>
#include <stdio.h>
int firstMissingPositive(int* nums, int numsSize){
    int i, temp;

    for(i = 0; i < numsSize; ++i){
        // index = nums[i] - 1;
        // while(index > 0 && index < numsSize && nums[index] != index+1;
        while((nums[i] > 0) && (nums[i] < numsSize) && (nums[nums[i] -1] != nums[i])){
            // 换的顺序要注意，
            temp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = temp;
        }
    }
    for(i = 0; i < numsSize; ++i){
        if(nums[i] != (i+1))
            return i+1;
    }
    return i+1;
}
int main(){
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(*arr);
    int *nums = malloc(sizeof(int) * size);
    for(int i = 0; i < size; ++i)
        nums[i] = arr[i];
    int ret = firstMissingPositive(nums, size);

    printf("%d\n", ret);
}