//
// Created by ear on 12/13/22.
//
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void str_cpy(char *from, char *to, int len){
     for(int i = 0; i < len; ++i){
         to[i] = from[i];
     }
     return;
 };
 void dfs(int n, int index, int l, int r, char **ret, char *stack, int *count){
     if(index == n*2){
         ret[*count] = malloc((index+1)*sizeof(char));
         str_cpy(stack,ret[*count],index+1);
         (*count)++;
         return;
     }

     if(l < n){
         stack[index] = '(';
         dfs(n, index+1, l+1, r, ret, stack, count);
     }

     if(r < l){
         stack[index] = ')';
         dfs(n, index+1, l, r+1, ret, stack, count);
     }
 }
char ** generateParenthesis(int n, int* returnSize){
    char* stack = calloc(n*2+1 , sizeof(char));
    char** ret = malloc(5000*sizeof(char*));

    *returnSize = 0;
    dfs(n,0,0,0,ret,stack, returnSize);

    return ret;
}