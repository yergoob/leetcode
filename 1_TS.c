/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 2 <= nums.length <= 10e3
// -10e9 <= nums[i] <= 10e9
// -10e9 <= target <= 10e9
#include <stdlib.h>
#include <stdio.h>

#define hash_len 1000

void init_hash_tab (void);
int* twoSum (int* nums, int numsSize, int target, int* returnSize);
int another_index (int nums_i, int key);
int hash_k(int key);  // search the point
void save_nums_i(int key, int i_ndex);

struct table{
	int index;	
	int val;		
}hash_tab[hash_len];

void init_hash_tab () {
	int i;

	for (i = 0; i < hash_len; ++i){
		hash_tab[i].index = -1;
		hash_tab[i].val = -1;	//bug: if the "targe - nums[i] == -1", here is wrong;
	}
	return;
}

int another_index (int nums_i, int key){
	int k;

	k = hash_k(key);
	if (hash_tab[k].index == -1){	//not found
		return -1;
	}else
		return hash_tab[k].index;
}

int hash_k(int key){  // search the point
	int k;
	
	k = (key % hash_len);
    if( k < 0)
        k = -k;
	while(hash_tab[k].index != -1 && hash_tab[k].val != key)
		k = (k +1) % hash_len;
	return k;
}

void save_nums_i(int key, int i_ndex){
	int k;

	k = hash_k(key);
	hash_tab[k].val = key;
	hash_tab[k].index = i_ndex;
	return;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i;
	
	int* ret = (int*)malloc(sizeof(int)*2);

	init_hash_tab();
		
	for (i = 0; i < numsSize; ++i){
		ret[0] = another_index(nums[i], target - nums[i]);
		if(ret[0] != -1){
			ret[1] = i;
            *returnSize = 2;
			break;
		}
		else
			save_nums_i(nums[i], i);
	}
	return ret;
}

#if 0
int main(){
	int target = 9;
	int* nums;
	int* returnSize;
	
	nums = malloc(sizeof(int)*4);
	nums[0] = -1;
	nums[1] = 10;
	nums[2] = 11;
	nums[3] = 15;
	returnSize = twoSum(nums, 4, target);

	printf("[%d, %d]\n", returnSize[0], returnSize[1]);

	return 0;

}
#endif
