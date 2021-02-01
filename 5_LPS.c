#include <stdlib.h>
#include <stdio.h>

struct sub_s{
	int l;
	int r;
	int lenth;
};

struct sub_s*  count_sub_s (char* s, int i);
char * longestPalindrome(char * s);

struct sub_s*  count_sub_s (char* s, int i){
	struct sub_s* p = malloc(sizeof(struct sub_s));
	int left, right;
	
	left = i - 1;
	right = i + 1;

	while (left >= 0 && s[left] == s[i])
		--left;
	while (s[right] != '\0' && s[right] == s[i])
		++right;
/*
	if (left < 0){
		if (s[i] == s[right])
			++right;
	}
	if (s[right] == '\0'){
		if (left >= 0 && s[left] == s[i])
			--left;
	}
	if (left >= 0 && s[right] != '\0'){
		if (s[left] != s[right]){
			if (s[left] == s[i])
				--left;
			if (s[right] == s[i])
				++right;
		}
	}
*/
	while (left >= 0 && s[right] != '\0'){
		if ( s[left] ==  s[right] ) {
			--left;
			++right;
		}else
			break;

	}
	
	++left;
	--right;
	p->l = left;
	p->r = right;
	p->lenth = (right - left);
	
	return p;
}
char * longestPalindrome(char * s){
	struct sub_s *max, *p;
	int i;

	max = malloc(sizeof(struct sub_s));

	for (i = 0; s[i] != '\0'; ++i){
		p = count_sub_s(s, i);
		if (p->lenth > max->lenth){
			max->l = p->l;
			max->r = p->r;
			max->lenth = p->lenth;
		}
	}
	s[++(max->r)] = '\0';
	return &s[max->l];
}
