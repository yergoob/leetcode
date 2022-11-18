#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10001
bool isValid(char * s){
	char stack[MAX_LEN];int top = 0;
	int i;

	for(i = 0; s[i] != '\0'; ++i){
		if(s[i] == '(' || s[i] == '{' || s[i] == '['){
			stack[top++] = s[i];
		}else{
			if(top != 0){
				if(s[i] == ')' && stack[--top] == '('){
					continue;
				}else if(s[i] == '}' && stack[--top] == '{'){
					continue;
				}else if(s[i] == ']' && tack[--top] == '['){
					continue;
				}else{
					++top;
					break;
				}
					
			}else{
				++top;//这个是为了防止只输入)}]当中的任何一个
				break;
			}
		}
	}
	if(top == 0)
		return true;
	else
		return false;
			
}
