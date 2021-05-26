#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int roman_index;

char * intToRoman(int num);
void get_roman(char* to, char* from);

char * intToRoman(int num){
	int n[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	char *r[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

	char *roman = malloc(sizeof(char)*20);

	roman_index = 0;
	for (int i = 0; i < 13; ++i) {
		while (num >= n[i]) {
			num -= n[i];
			get_roman (roman, r[i]);
		}
	}
	return roman;
}
void get_roman(char* to, char* from) {
	for (int i = 0; from[i] != '\0'; ++i, ++roman_index)
		to[roman_index] = from[i];
	to[roman_index] = '\0';
	return;
}
void main() {
	char *c = intToRoman(3990);
	
	for (int i = 0; c[i] != '\0'; ++i)
		putchar(c[i]);
	printf("\n");
	return;
}

