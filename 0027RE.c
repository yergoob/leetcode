//
// Created by ear on 12/22/22.
//
#include <stdio.h>
int removeElement(int* nums, int numsSize, int val){
    int i, j;

    if(numsSize == 0)
        return 0;

    for(j= 0; j < numsSize; ++j){
        if(nums[j] != val){
            if (j == 0)
                i = 1;
            else
                nums[i++] = nums[j];
        }else
            if (j == 0)
                    i = 0;
    }
    return i;
}
int main(){
    int nums[] = {0,1,2,2,3,0,4,2};
    int size = sizeof(nums)/sizeof(*nums);

    int i = removeElement(nums, size, 2);

    printf("%d,\n", i);
    for(int j = 0; j < i; ++j){
        printf("%d, ", nums[j]);
    }
    printf("\n");
}