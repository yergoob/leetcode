/* 0<= s.length <= 5 * 10e4 */
// use quenen and array;

#include <stdio.h>

#define SIZE 256
#define NO_APPEAR 0

int lengthOfLongestSubstring(char * s);

int lengthOfLongestSubstring(char * s){
	char array[SIZE] = {NO_APPEAR};
	char queue[SIZE];
	int rear = 0, front = 0;
	int i = 0, max_count = 0, count = 0;

	while(s[i] != '\0'){
		while(s[i] != '\0' && array[(int)s[i]] == NO_APPEAR){ 
			rear = (rear + 1) % SIZE;
			queue[rear] = s[i];
			++array[(int)s[i]];
			++count;
			++i;	
		}
		if(count > max_count)
			max_count = count;
		if(s[i] != '\0'){
			while(1){
				--count;
				front = (front + 1) % SIZE;
				array[(int)queue[front]] = NO_APPEAR;
				if(queue[front] != s[i])
					continue;
				else
					break;
			}
		}
	}
	return max_count;
}

#if 0
int main (){
	char* s = "abcabcbb";
	int n;

	n = lengthOfLongestSubstring(s);

	printf("%d\n", n);
}
#endif
