// 38. 外观数列
// Created by ear on 1/5/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXLENGTH 1000
struct countArray{
    int num;    // 数字
    int n;      // 有几个
};
int count(int *a, struct countArray* ca, int *a_len){
    int i;
    int count = 0;

    ca[count].num = a[0];
    ca[count].n = 1;
    for(i = 1; i < *a_len; ++i){
        if(a[i] == a[i-1]){
            ++(ca[count].n);
        }else{
            ++count;
            ca[count].num = a[i];
            ca[count].n = 1;
        }
    }
    return count+1;
}
int say(struct countArray* ca, int *a, int* ca_len){
    int i;
    int len = 0;

    for(i = 0; i < *ca_len; ++i) {
        a[len++] = ca[i].n;
        a[len++] = ca[i].num;
    }
    return len;
};
char * countAndSay(int n){

    char* ret = malloc(sizeof(char)*MAXLENGTH);
    int *a = malloc(sizeof(int)*MAXLENGTH);
    struct countArray *ca = malloc(sizeof(struct countArray)*MAXLENGTH);
    
    a[0] = 1;
    int a_len = 1;
    int ca_len = 0;
    int i;
    if(n != 1){
        for(i = 1; i < n; ++i){
            ca_len =  count(a, ca, &a_len);
            a_len = say(ca, a, &ca_len);
        }
    }

    for(i = 0; i < a_len; ++i){
        ret[i] = a[i] + '0';
    }
    ret[i] = '\0';

    return ret;
}
int main(){
    int n = 1;
    char* ret = malloc(sizeof(char)*MAXLENGTH);

    ret = countAndSay(n);

    printf("%s\n", ret);
}