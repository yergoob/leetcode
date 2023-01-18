// 44. 通配符匹配
// Created by ear on 1/11/23.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool isMatch(char * s, char * p){
    char* last_s = NULL;
    char* last_p = NULL;

    while(*s != '\0'){
        if(*p == '*'){
            if(*++p == '\0')    // 匹配到p的最后一位是‘*’
                return true;
            last_p = p;
            last_s = s;
        }else if(*p == '?' || *s == *p){
            ++s;
            ++p;
        }else if(last_s != NULL){
            p = last_p;
            s = ++last_s;
        }else{
            return false;
        }
    }
    while(*p == '*')
        ++p;

    return *p == '\0';
}
int main(){
    char a[] = {'a','d', 'c', 'e', 'b','\0'};
    char b[] = { '*', 'a', '*', 'b', '\0'};

    char *s = &a[0];
    char *p = &b[0];

//    printf("s: %s\n, p: %s\n", s, p);

    bool ret = isMatch(s, p);

    if (ret == true) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}