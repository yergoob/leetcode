//
// Created by ear on 12/29/22.
//
#include <stdio.h>
void reverse(int* nums, int i, int j){
    int temp;
    while(i < j){
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        ++i;
        --j;
    }
}
void nextPermutation(int* nums, int numsSize){
    int small, large, temp;
    int reverse_i, reverse_j = numsSize-1;
    for(small = numsSize-1; small >= 0; --small){
        if(small-1 >= 0){
            if(nums[small-1] < nums[small]){
                reverse_i = small;
                --small;
                break;
            }
        }
    }
    if(small >= 0){
        for(large = numsSize-1; nums[large] <= nums[small]; --large);
        temp = nums[small];
        nums[small] = nums[large];
        nums[large] = temp;
    }else
        reverse_i = 0;
    while(reverse_i < reverse_j){
        temp = nums[reverse_i];
        nums[reverse_i]= nums[reverse_j];
        nums[reverse_j--]= temp;
        ++reverse_i;
    }
}
int main(){
    int nums[] = {1,5,1}; // [5,1,1]
    int size = sizeof(nums)/sizeof(*nums);
    nextPermutation(nums, size);
    for(int i = 0; i < size; ++i){
        printf("%d,", nums[i]);
    }
    printf("\n");
    return 0;
}