// 42. 接雨水
// Created by ear on 1/9/23.
//  方法二： 双指针法
//
//
#include <stdlib.h>
#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a < b ? a : b;
}
int trap(int* height, int heightSize){
    int l = 0, r = heightSize-1, maxl = 0, maxr = 0;
    int ret = 0;

    while(l < r){
        maxl = max(height[l], maxl);
        maxr = max(height[r], maxr);
        if(height[l] > height[r]){  // 若左边柱子高，
            ret += min(height[l], maxr) - height[r];
            --r;
        }else{
            ret += min(height[r], maxl) - height[l];
            ++l;
        }
    }
    return ret;
}
int main(){
    int h[] = {4,2,3,4};
    int size = sizeof(h)/sizeof(*h);
    int *height = malloc(sizeof(int)*size);
    int i;
    for(i = 0; i < size; ++i){
        height[i] = h[i];
    }
    i = trap(height, size);
    printf("%d\n", i);
}