#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10000
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void q_sort(int* arr, int low, int high){
	int j,k,temp;

	if(low >= high)
		return;
	temp = arr[low];
	j = low;
	k = high;
	while(j<k){
		while(j<k && arr[k]>=temp){--k;}
		if(j<k){
			arr[j++] = arr[k];
		}
		while(j<k && arr[j]<=temp){++j;}
		if(j<k){
			arr[k--] = arr[j];
		}	
	}
	arr[j]=temp;
	q_sort(arr,low,j-1);
	q_sort(arr,k+1,high);
}
void mem_cpy(int *to,int* from, int total){
	int i;
	for(i = 0; i<total; ++i){
		to[i] = from[i];
	}
}	
void kSum(int* nums,int low,int high,int k,int total_k,double target,int* stack,int stack_len,
		int** ret,int* returnSize,int* ret_cloum){
	int i;
	if(k == 2){
		while(low<high){//-2,-1,0,0,1,2
			int sum = nums[low]+nums[high];
			if(sum > target){
				--high;
			}else if(sum < target){
				++low;
			}else{
				stack[stack_len++] = nums[low];
				stack[stack_len++] = nums[high];
				ret[*returnSize] = malloc(sizeof(int)*total_k);
				mem_cpy(ret[*returnSize],stack,total_k);
				ret_cloum[*returnSize] = total_k;//之前竟然把这一句写在了++(*returnSize)后面 导致结果中的第一行输不出来
				++(*returnSize);
				stack_len -= 2;
				while(++low<high && nums[low]==nums[low-1]){}
				while(--high>low && nums[high]==nums[high+1]){}
			}
		}

	}else{
		for(i=low;i<=high-k+1;++i){
			if(i>low && nums[i] == nums[i-1]){continue;}
			//stack[stack_len++] = nums[i]; 注意这里的stack_len这这里加完的话 递归回退的时候stack_len
			//值就不正确，应该在传参的函数里加
			stack[stack_len] = nums[i];
			kSum(nums,i+1,high,k-1,total_k,target-nums[i],stack,stack_len+1,ret,returnSize,ret_cloum);
			//kSum(nums,i+1,high,k-1,total_k,target-nums[i],stack,stack_len,ret,returnSize,ret_cloum);
		}			
	}

}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
	int i;	

	*returnSize = 0;
	if(numsSize < 4){
		return NULL;
	}
	int* stack = malloc(sizeof(int)*4);
	int stack_len =0;
	int** ret = malloc(sizeof(int*)*CAPACITY);
	*returnColumnSizes = malloc(sizeof(int)*CAPACITY);
	
	q_sort(nums, 0, numsSize-1);
	kSum(nums,0,numsSize-1,4,4,target,stack,stack_len,ret,returnSize,*returnColumnSizes);
	
	return ret;

}
int main(){
	int i, count, target =-294967296, *col_sizes;
	//int nums[] = {1,0,-1,0,-2,2};//[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
	//int nums[] = {-3,-2,-1,0,0,1,2,3};
	//int nums[] = {0,1,5,0,1,5,5,4};
	//int nums[] = {2,2,2,2,2};
	//int nums[] = {0,0,0,0};
	int nums[] = {1000000000,1000000000,1000000000,1000000000};

	int **quadruplets = fourSum(nums,sizeof(nums)/sizeof(*nums),target,&count,&col_sizes);
	for(i = 0; i<count; ++i){
		for(int j = 0; j < col_sizes[i];++j){
			printf("%d ",quadruplets[i][j]);
		}
		printf("\n");
//		printf("%d %d %d %d\n", quadruplets[i][0], quadruplets[i][1], quadruplets[i][2], quadruplets[i][3]);
	}
	return 0;
}	
	
