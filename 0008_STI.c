/*signed iteger overflow: 2147483640 + 8 cannot be represented in type 'int' [solution.c] *
 *
 * */
#include <stdio.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define POSITIVE 1
#define NEGATIVE -1 
int edge_solve (int n, int sign, char* s) {
	//n >= MAX_INT/10
	if (sign > 0) {
		if (*s - '0' > 7 || n > MAX_INT/10)
			return MAX_INT;
		else {
			n = n*10 + (*s++ - '0');
			if ( *s - '0' >= 0 && *s - '0' <= 9)
				return MAX_INT;
			else
				return n;
		}
	}
	else {
		if (*s - '0' > 8 || n > MAX_INT/10)
			return MIN_INT;
		else {
			n = n*sign*10 + sign*(*s++ - '0');
			if (*s - '0' >= 0 && *s - '0' <= 9)
				return MIN_INT;
			else
				return n;
		}
	}
}
int get_ret (char* s, int sign) {
	int n = 0;

	while ((*s - '0' >= 0) && (*s - '0' <= 9)){
		if (n < MAX_INT/10) 
			n = n*10 + (*s++ - '0');
		else 
			return edge_solve (n, sign, s);
	}
	return n*sign;
}

int myAtoi(char * s){
	int retSign = POSITIVE;

	while (*s == ' ') ++s;
	if (*s == '-') {
		++s;
		retSign = NEGATIVE;
	}else if (*s == '+')
		++s;
	if ((*s - '0') >= 0 && (*s - '0') <= 9) {
		return  get_ret (s, retSign);
	}else return 0;
}
/*
void main() {
	char* s = "21474836460";
	printf("%d\n", myAtoi(s));	
}
*/
