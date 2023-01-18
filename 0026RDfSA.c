//
// Created by ear on 12/22/22.
//
#include <stdio.h>
#include <stdlib.h>
int removeDuplicates(int* nums, int numsSize){
    int i, j;

    for(i = 1, j = 1; j < numsSize; ++j){
        if(nums[j] == nums[j-1]){
            continue;
        }else{
            nums[i++] = nums[j];
        }
    }
    return i;
}
int main(){
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int size = sizeof(nums)/sizeof(*nums);

    int i = removeDuplicates(nums, size);

    printf("%d,\n", i);
    for(int j = 0; j < i; ++j){
        printf("%d, ", nums[j]);
    }
    printf("\n");
}