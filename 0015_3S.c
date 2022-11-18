#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void q_sort(int* arr, int left, int right){
	int temp;
	int l,r;

	if(left >= right)
		return;
	l = left;
	r = right;
	temp = arr[l];
	while(l < r){
		while(l<r && arr[r] >= temp)--r;
		if(l<r){
			arr[l] = arr[r];
			++l;
		}		
		while(l<r && arr[l] <= temp)++l;
		if(l<r){
			arr[r] = arr[l];
			--r;
		}
	}	
	arr[l] = temp;
	q_sort(arr,left,l-1);
	q_sort(arr,r+1,right);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int i,j,k;
	int sum;
	
	*returnSize = 0;
	if(numsSize < 3){
		return NULL;
	}
	
	q_sort(nums,0,numsSize-1);

	int **ret = malloc(sizeof(int*)*50000);

	for(i = 0; i < numsSize-2; ++i){
		if(nums[i] > 0){
			break;
		}
		if(i == 0 || i > 0 && nums[i] != nums[i-1]){
			j = i+1;
			k = numsSize-1;
			while(j < k){
				sum = nums[i] + nums[j] + nums[k];
				if (sum > 0){
					--k;
				}
				else if(sum < 0){
					++j;
				}
				else{
					ret[*returnSize] = malloc(sizeof(int)*3);
					ret[*returnSize][0] = nums[i];	
					ret[*returnSize][1] = nums[j];	
					ret[*returnSize][2] = nums[k];	
					++(*returnSize);
					while(++j<k && nums[j]==nums[j-1]){}
					while(--k>j && nums[k]==nums[k+1]){}
				}
			}	
		}
	}
	
	// 就一直卡在这个上面吗？？难受的returnColumnSizes 
	*returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
	for(i = 0; i < (*returnSize); ++i){
		(*returnColumnSizes)[i] = 3;
	}

	return ret;
}

