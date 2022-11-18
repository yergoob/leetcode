#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
	
	int i,j,k;

	int digits_len = strlen(digits);
	// 存储数字所对应的字符串和长度
	char* letters_matrix[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int letters_length[8] = {3,3,3,3,3,4,3,4};
	
	if(digits_len == 0){
		*returnSize = 0;
		return NULL;	
	}

	int count = 1; 
	for(i = 0; i < digits_len; ++i){
		count *= letters_length[digits[i] - '2'];	
	}

	*returnSize = count;
	
	char** ret = (char**)malloc(sizeof(char*)*count);
	for(i = 0; i < count; ++i){
		ret[i] = (char*)malloc(sizeof(char)*(digits_len+1));
		memset(ret[i], 0, digits_len+1);
	}

	// 这是第一组字符要填装的次数
	int den = 1;
	for(i = digits_len -1; i > 0; --i){
		den *= letters_length[digits[i] - '2'];
	}
	
	int col = 0;
	/* 核心函数，每一层循环向结果数组里填装一组digits[i]所对应的字符
	 * 例如 2：abc    要填 den=3*4*4次
	 * 	3: def	       den=4*4次
	 * 	7: pqrs        den=4次
	 * 	9: wxyz        den=1次
	 *
	 * 	index：是那一组字符串
	 * 	k：    是这组字符串的第几个字符
	 * 	       k很关键：如先填abc den=42次
	 * 	       		0-47   k=0 letters_matrix[index][k]==a
	 * 	       		48-95  k=1 letters_matrix[index][k]==b
	 * 	       		96-143 k=2 letters_matrix[index][k]==c
	 * 	       接着进入第二次循环，即要填返回数据的第二列，也就是要填def
	 * 	       。。。。
	 * 	col：  是要返回的二维数组的列
	 * 	
	 **/
	for(i = 0; i < digits_len; ++i){
		int index = digits[i] - '2';
		if( i > 0) {
			// 填装的该组字符要填装的次数
			den /= letters_length[index];
		}	
		for(j = 0 ; j < count; ++j){
			k = j / den % letters_length[index];
			ret[j][col] = letters_matrix[index][k];
		}
		++col;
	}
       	return ret;	
}
int main(){}
