//
// Created by ear on 12/28/22.
//
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
inline bool strCmp(char* a, char* b) {
    while (*a && (*a == *b++))
        ++a;
    return !*a;
}

int* hitPostions;

int wordsMatch(char* s, char** words, int wordsSize, int wordLen) {
    memset(hitPostions, -1, wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize * wordLen; i += wordLen)
        for (int j = 0; j <= wordsSize; j++) {
            if (j == wordsSize) return 0;
            if (hitPostions[j] == -1)
                if (strCmp(words[j], s + i)) {
                    hitPostions[j] = i;
                    break;
                }
        }
    return 1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int* result = malloc(20 * sizeof(int)), wordLen = strlen(words[0]);
    *returnSize = 0;
    hitPostions = malloc(wordsSize * sizeof(int));
    for (int k = 0; s[k + wordLen * wordsSize - 1]; k++)
        if (wordsMatch(s + k, words, wordsSize, wordLen)) {
            result[*returnSize] = k;
            (*returnSize)++;
        }
    return result;
}
int main(){
    char* words[] = {
            "bar",
            "foo",
            "the"
    };
    char* s = "barfoofoobarthefoobarman";

    int ret;
    int *i;
    i = findSubstring(s, words, 3, &ret);
    printf("%d\n", *i);
}