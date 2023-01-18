// 42. 接雨水
// Created by ear on 1/9/23.
//  方法二： 单调递减栈**
//          当栈不空且栈顶元素所对应柱子的高度小于当前遍历到的柱子的高度，就出栈计算（长*宽））
//
#include <stdlib.h>
#include <stdio.h>
int min(int a, int b){
    return a < b ? a : b;
}
int trap(int* height, int heightSize){
    int i = 0, ret = 0;
    int *stack = malloc(sizeof(int)*heightSize);int top = -1;

    while(i < heightSize){
        if(top != -1 && height[i] > height[stack[top]]){  // 出栈, 当前高度大于栈顶元素位置的高度
            if((top-1) == -1){  // 若左边没有柱子了， 就接不了雨水，
                --top;
                continue;
            }
            // 只要栈中还有超过两个元素， 也就是左边还有不少于两根柱子，又因为是单调递减栈，所以就可以接雨水
            // 注意这个宽度的计算 i-stack[top-1]-1; 我之前写的是 i-stack[top]
            ret += (i-stack[top-1]-1)*(min(height[stack[top-1]], height[i])-height[stack[top]]);
            --top;
        }else
            stack[++top] = i++;
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