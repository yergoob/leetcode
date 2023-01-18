//
// Created by ear on 12/29/22.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int get_max(int a, int b){
    return a>b ? a : b;
}
int longestValidParentheses(char * s){
    int s_len = strlen(s);

    int maxl = 0;

    int* stack = malloc(sizeof(int)*(s_len+1)); int top = -1;
    stack[++top] = -1;
    for(int i = 0; i < s_len; ++i){
        if(s[i] == '('){
            stack[++top] = i;
        }else{
            --top;
            if(top == -1){
                stack[++top] = i;
            }else{
                maxl = get_max(maxl,i-stack[top]);
            }
        }
    }
    return maxl;
}
int main(){
    char s[] = "()())";
    int ret = longestValidParentheses(s);
    printf("%d\n", ret);
}