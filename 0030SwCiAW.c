//
// Created by ear on 12/27/22.
//
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /**
  *  滑动窗口：窗口大小就是wordsSize*words[i].length,
  *          把words全部装进哈希表，然后就遍历整个s的子串
  *          子串的长度就是窗口的大小，
  *          当子串和哈希表相同，就是找到了，
  *  重点： 对于C语言如何构建字符串哈希表，
  *        这道题中若要对words构建哈希表，
  *        就是words[i]中的字符串要对应一个数字，这数字做哈希表下表，从而快速找到
  *  如何对words[i]构建对应的数字:
  *        1 <= words.length <= 5000 :让哈希表 = 5000
  *        1 <= word[i].length <= 30
  *        用一个32位前26个比特位 来表示abc这26个字符在那个位置上出现了。
  *
  */
#include <string.h>
#include <stdlib.h>

int* get_words_map(char** words, int wordsSize, int wordsi_len){}
int* get_temp_map(char*s, int i, int len){}
int test_tempmap_in_map(int*)
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int s_len, wordsx_len, sub_s_len;

    s_len = strlen(s);
    wordsx_len = strlen(words[0]);
    sub_s_len = wordsx_len*wordsSize;
    *returnSize = 0;
    if(s_len < sub_s_len){
        return NULL;
    }

    char** wordsList = malloc(sizeof())
    words_map = get_words_map(words, wordsSize, wordsi_length);
    int *ret = malloc(sizeof(int)*wordsSize);

    int i, *temp_map, count = 0, index;
    for(i = 0; i < sub_slen; ++i){
        temp_map = get_temp_map(s, i, sub_slen);
        index = test_tempmap_in_map(temp_map, words_map)
        if(index >= 0){
            ret[count++] = index;
        }
    }

    return ret;
}