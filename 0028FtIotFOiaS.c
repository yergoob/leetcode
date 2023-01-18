//
// Created by ear on 12/22/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_nextval(char* substr, int s_lenth, int* nextval){
    int t = -1, j = 0;
    nextval[0] = -1; //j==0 默认-1，j==1 默认0

    while(j < (s_lenth-1)){
        if(t == -1 || substr[j]  == substr[t]){
            ++j;
            ++t;
            if(substr[j] == substr[t]){
                nextval[j] = nextval[t];
            }else{
                nextval[j] = t;
            }
        }else
            t = nextval[t];
    }
}
int strStr(char * haystack, char * needle){
    int s_lenth, subs_lenth, *nextval;
    int i = 0, j = 0;

    s_lenth = strlen(haystack);
    subs_lenth = strlen(needle);
    if(subs_lenth > s_lenth)
        return -1;

    nextval = malloc(sizeof(int)*subs_lenth);
    get_nextval(needle, subs_lenth, nextval);
    // test nextval array
    for(int k = 0; k < subs_lenth; ++k){
        printf("%d == %d\n", k , nextval[k]);
    }

    while(i < s_lenth){
        if(j == -1 || haystack[i] == needle[j]){
            ++i;
            ++j;
            // 这里还可以做一个假设 如何主串未匹配长度小于模式串未匹配长度， 就是找不到了，应该结束掉
            if((s_lenth-i) < (subs_lenth-j))
                return -1;
        }else{
            j = nextval[j];
        }
        if(j == subs_lenth){
            return i - j;
            // i = aaaad // i = 4
            // j = aaaa // j = 4
        }
    }
    free(nextval);
    return -1;
}
int main(){
    char h[] = "ddddaaa";
    char n[] = "aaaa";
    int ret = strStr(h, n);
    printf("%d\n", ret);
}