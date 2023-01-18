// 35. Search Insert Position
// Created by ear on 12/31/22.
//
int searchInsert(int* nums, int numsSize, int target){
    int index, l = 0, r = numsSize-1, mid;

    while(l < r){
        mid = (r+l)/2;
        if(target < nums[mid])
            r = mid;
        else if(target > nums[mid])
            l = mid+1;
        else
            return mid;
    }
    if(target < nums[0])
        index = 0;
    else if(target > nums[numsSize-1])
        index = numsSize;
    else{
        if(target <= nums[l])
            index = l;
        else
            index = ++l;
    }
    return index;
}