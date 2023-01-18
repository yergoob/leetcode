// 49. 字母异位词分组
// Created by ear on 1/17/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct words_hash{
    int n;
    char* words;
    int index[10];
};
static int compare(const void *a, const void *b){
    return *(char*)a - *(char*)b;
}
int BKDRHash(char* s, int size){
    int seed = 31;       /* 131, 1313. 13131, ... */
    unsigned long hash = 0;
    while(*s != '\0'){
        hash = hash *  seed + *s++;
    }
    return hash % size;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    struct words_hash* ht = calloc(strsSize,sizeof(struct words_hash));
    char* strs_i;
    int i, j, k;
    *returnSize = 0;
    for(i = 0; i < strsSize; ++i){
        int len = strlen(strs[i]);
        strs_i = malloc(sizeof(char)*(len+1));
        strcpy(strs_i, strs[i]);
        qsort(strs_i, len, sizeof(char), compare);
        int hash = BKDRHash(strs_i, strsSize);
//        ht[hash].words = strs_i;
//        if(strcmp(strs_i, ht[hash].words))    // if(0) 就不会进去， 除了零都可以进去 而strcmp相同就返回0
        for(j = hash; ht[j].n > 0 && strcmp(ht[j].words, strs_i); j = (j+1)%strsSize/*注意这里是求余*/){}
        if(ht[j].n == 0){
            ht[j].words = strs_i;
            ++(*returnSize);
        }
        ht[j].index[ht[j].n++] = i;
    }
    char*** ret = malloc(sizeof(char**)*(*returnSize));
    *returnColumnSizes = malloc(sizeof(int)*(*returnSize));
    for(i = 0, k = 0; i < strsSize; ++i){
        if(ht[i].n > 0){
            ret[k] = malloc(sizeof(char*) * (ht[i].n));
            (*returnColumnSizes)[k] = ht[i].n;
            for(j = 0; j < ht[i].n; ++j){
                ret[k][j] = strs[ht[i].index[j]];
            }
            ++k;
        }
    }
    return ret;
}
int main(){
    int strsSize = 2;
    int * returnColumnSizes;
    char s[6][4] = {"","b"};
    char** strs = malloc(sizeof(char*)*strsSize);

    for(int i = 0; i < strsSize; ++i)
        strs[i] = &s[i];

    // test strs
    for(int i = 0; i < strsSize; ++i){
        printf("%s,", strs[i]);
    }
    printf("\n");

    int returnSize;
    char*** ret = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; ++i){
        for(int j = 0; j < returnColumnSizes[i]; ++j){
            printf("%s,", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}