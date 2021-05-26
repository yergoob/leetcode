#include <stdio.h>

int symbolIndex(char c);
int romanToInt(char * s);

int symbolIndex(char c) {
	char sym[7] = "MDCLXVI";
	int i = 0;

	while (sym[i] != c)
		++i;
	return i;
}
int romanToInt(char * s){
	int value[7] = {1000, 500, 100, 50, 10, 5, 1,};
	int ret = 0;

	while (*s != '\0') {
		if (*(s+1) != '\0') {
			if (value[symbolIndex(*s)] < value[symbolIndex(*(s+1))]) {
				ret -= value[symbolIndex(*s)];
			}else
				ret += value[symbolIndex(*s)];
		}else {
			ret += value[symbolIndex(*s)];
		}
		++s;
	}
	return ret;
}
void main() {
	char* s = "MCMXCIV";

	printf("%d\n", romanToInt(s));
	return;
}
