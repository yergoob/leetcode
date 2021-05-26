#include <stdio.h>
#include <stdlib.h>

char * longestCommonPrefix(char ** strs, int strsSize);
int prefix(char* first, char* second);
char * copyRet(char* from, int size);

char * copyRet(char* from, int size) {
	char *ret = malloc(sizeof(char)*size + 1);

	int i;
	for( i = 0; i < size; ++i)
		ret[i] = from[i];
	ret[i] = '\0';
	return ret;
}
int prefix(char* first, char* second) {
	int i;

	for(i = 0; (first[i] == second[i]) && first[i] != '\0' && second[i] != '\0'; ++i);
	return i;
}
char * longestCommonPrefix(char ** strs, int strsSize){
	int max = 0, temp;
	int i;

	if (strsSize == 1)
		return strs[0];
	for (i = 0; i < (strsSize - 1); ++i) {
		temp = prefix(strs[i], strs[i+1]);
		if (temp < max || i == 0)
			max = temp;
		if (max == 0)
			break;
	}	
	return copyRet(strs[0], max);	
}
void main() {
	char *strs[2] = {
		"",
		""
	};
	char *s = longestCommonPrefix(strs, 2);
	printf("%s\n", s);
	return;
}
