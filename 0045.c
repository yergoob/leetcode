// 45. 跳跃游戏 II
// Created by ear on 1/12/23.
//
#include <stdlib.h>
#include <stdio.h>
int get_max(int* nums, int i, int index1){
    int max = index1;
    for(; i < index1; ++i){
        if((i+nums[i]) > (max+nums[max]))
            max = i;
    }
    return max;
}
int jump(int* nums, int numsSize){
    int step = 0;
    int index;
    
    int i = 0;
    while(i < numsSize-1){
        index = i + nums[i];
       if(index >= numsSize-1){
           return ++step;
       }else{
           i = get_max(nums, i+1, index);
           ++step;
       }
    }
    return step;
}
int main(){
//    int arr[] = {2,3,1,10,4,1,1,1,1,1,1,1,1,1,1,1};
    //                           1     10                                                               1      1      1
    //                     1                  4                       1     1      1      1      1      1      1      1  
    //                     1           10                                                               1      1      1           
//    int arr[] = {2,3,1,1,4,1,1,1,1,1,1,1,1,1,1,1};
    //                     3                 4                       1     1      1      1      1      1      1      1
    //                           1     1     4                       1     1      1      1      1      1      1      1
    int arr[] = {9,8,2,2,0,2,2,0,4,1,5,7,9,6,6,0,6,5,0,5};
    //               9                                                     1      5             9                                                5   
    //               9                                               4                          9                                                5  
    int *nums = &arr[0];
    int numsSize = sizeof(arr)/sizeof(*arr);
    int ret = jump(nums, numsSize);
    printf("%d\n", ret);
}