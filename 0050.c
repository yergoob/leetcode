// 50. Pow(x, n)
// Created by ear on 1/17/23.
//
#include <stdio.h>
#include <limits.h>
double fast_pow(double x, int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    double t = fast_pow(x, n/2);
    // n为奇数返回 t*t*x 偶数返回的是t*t
    //printf("n&1 = %d\n", n&1);
    return n & 1 ? t*t*x : t*t;
}
double myPow(double x, int n){
    // 对于n=INT_MIN=-2147483648 -n在int里面装不下
    if(n == INT_MIN){
        double t = (1 / fast_pow(x, -(n/2)));
        return t*t;
    }
    return n > 0 ? fast_pow(x, n) : (1 / fast_pow(x, -n));
}
//double myPow(double x, int n){
// 这个竟然在提交的时候通过了，， 可能是当n=INT_MIN时，x=1， 1的所有次方都是一 在此记录一下
//    return n > 0 ? fast_pow(x, n) : (1 / fast_pow(x, n));
//}
int main(){
    int n = 9;
    double x = 2.00000;

    double ret = myPow(x, n);

    printf("%f\n", ret);
}