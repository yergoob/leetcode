// 43. 字符串相乘
// Created by ear on 1/10/23.
//  可以不用提前假设结果的长度， 直接弄个长一点的就OK
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXRETLEN 500
int put_this_number(int* nums, int n, int pos){
    int carry = 0;

    n = nums[pos] + n;
    while(1){
        carry = n / 10;
        nums[pos] = n % 10;
        if(carry != 0){
            n = nums[++pos] + carry;
        }else{
            break;
        }
    }
    return pos;
}
char * multiply(char * num1, char * num2){
    int len1, len2;
    char* ret = malloc(sizeof(char)*MAXRETLEN);
    int *arr = malloc(sizeof(int)*MAXRETLEN);
    memset(arr, 0, sizeof(int)*MAXRETLEN);

    len1 = strlen(num1);
    len2 = strlen(num2);
    if((len1 == 0) || ((len2 == 1) && num2[0] == '0'))
        return num2;
    if((len2 == 0) || ((len1 == 1) && num1[0] == '0'))
        return num1;

    int i, j, arr_len = 0;
    int m, n;
    for(i = len1-1, m = 0; i >= 0; --i, ++m){
        for(j = len2-1, n = 0; j >= 0; --j, ++n){
//            printf("arr_len: %d  加 %d\n", arr_len, (num1[i]-'0')*(num2[j]-'0'));
            arr_len = put_this_number(arr, (num1[i]-'0')*(num2[j]-'0'), m+n);
        }
    }
    for(i = arr_len, j = 0; i >= 0; --i, ++j){
        ret[j] = arr[i] + '0';
    }
    ret[j] = '\0';
    return ret;
}
int main(){
    char n1[] = {'9','1', '3', '3'};
    char n2[] = {'0'};// 结果56088
    int len1 = sizeof(n1)/sizeof(*n1);
    int len2 = sizeof(n2)/sizeof(*n2);
    printf("len1=%d, len2=%d\n", len1, len2);
    char* num1 = malloc(sizeof(char)*(len1+1));
    char* num2 = malloc(sizeof(char)*(len2+1));

    int i;
    for(i = 0; i < len1; ++i){
        num1[i] = n1[i];
    }
    for(i = 0; i < len2; ++i){
        num2[i] = n2[i];
    }
    char* ret = multiply(num1, num2);
    printf("%s\n", ret);
}