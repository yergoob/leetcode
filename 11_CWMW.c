#include <stdio.h>

int maxArea (int* height, int heightSize) {
	int i = 0, j = heightSize - 1;
	int s = 0, sjk; 
	int h;

	while ( i < j) {
		h = height[i] < height[j] ? height[i] : height[j];
		sjk = h * (j - i);
		if (sjk > s)
			s = sjk;
		if (h == height[i]) //如果height[i] < height[j]; 
			++i;
		else
			--j;
	}
	return s;
}
void main() {
	int height[] = {2,3,4,5,18,17,6};
	printf("%d\n", maxArea(height, 7));
}
