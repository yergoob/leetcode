// 42. 接雨水
// Created by ear on 1/9/23.
//  方法一： 动态规划
//          从左往右遍历得到左边柱子最大值leftMax, 从右向左遍历得到右边柱子最大值rightMax
//          当前位置的储水量就是左右柱子的最小值减去当前柱子的高度。
#include <stdlib.h>
#include <stdio.h>
int min(int a, int b){
    return a < b ? a : b;
}
// test
//void test(int* nums, int size){
//    for(int i = 0; i < size; ++i){
//        printf("%d,", nums[i]);
//    }
//    printf("\n");
//}
int trap(int* height, int heightSize){
    int *leftMax = malloc(sizeof(int)*heightSize);
    int *rightMax = malloc(sizeof(int)*heightSize);

    int i;
    for(i = 1, leftMax[0] = height[0]; i < heightSize; ++i){
        if(height[i] < leftMax[i-1])
            leftMax[i] = leftMax[i-1];
        else
            leftMax[i] = height[i];
    }
//    printf("test, leftMax : ");
//    test(leftMax, heightSize);
    for(i = heightSize-2, rightMax[heightSize-1] = height[heightSize-1]; i >= 0; --i){
        if(height[i] < rightMax[i+1])
            rightMax[i] = rightMax[i+1];
        else
            rightMax[i] = height[i];
    }
//    printf("test, rightMax: ");
//    test(rightMax, heightSize);
    int ret = 0;
//    printf("test, ret     : ");
    for(i = 0; i < heightSize; ++i){
        ret += min(leftMax[i], rightMax[i]) - height[i];
        printf("%d,", ret);
    }
//    printf("\n");
    return ret;
}
int main(){
    int h[] = {4,2,0,3,2,5};
    int size = sizeof(h)/sizeof(*h);
    int *height = malloc(sizeof(int)*size);
    int i;
    for(i = 0; i < size; ++i){
        height[i] = h[i];
    }
    i = trap(height, size);
    printf("%d\n", i);
}