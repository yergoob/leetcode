//
// Created by ear on 12/26/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor)
{
    int signal = 1;
    unsigned int dvd = dividend;
    printf("dividend: %X\n", dividend);
    if (dividend < 0) {
        signal *= -1;
        dvd = ~dvd + 1;
        printf("dvd: %X\n", dvd);
    }

    unsigned int dvs = divisor;
    printf("divisor: %X\n", divisor);
    if (divisor < 0) {
        signal *= -1;
        dvs = ~dvs + 1;
        printf("dvs: %X\n", dvs);
    }

    int shift = 0;
    while (dvd > dvs << shift) {
        shift++;
    }

    unsigned int res = 0;
    while (dvd >= dvs) {
        while (dvd < dvs << shift) {
            shift--;
        }
        res |= (unsigned int) 1 << shift;
        printf("dvd: %X\ndvs: %X\nres: %X\n", dvd, dvs, res);
        dvd -= dvs << shift;
    }

    if (signal == 1 && res >= INT_MAX) {
        return INT_MAX;
    } else {
        return res * signal;
    }
}

int main()
{
    int dividend = 10000;
    int divisor = -10;

    int ret = divide(dividend, divisor);
    printf("%d\n", ret);
    return 0;
}