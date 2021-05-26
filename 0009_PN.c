#include <stdio.h>
#include <stdbool.h>
bool isPalindrome(int x){
	int arrX[10];
	int i, j;

	if (x < 0)
		return false;
	
	for (i = 0; x != 0; ++i) {
		arrX[i] = x%10;
		x /= 10;
	}
	for (--i, j = 0; j < i; ++j, --i) {
		if (arrX[i] != arrX[j])
			break;
	}
	if (j >= i )
		return true;
	else
		return false;
}
void main () {
	printf ("%d \n", isPalindrome(10));
}
