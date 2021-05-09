//这题指针不初始化，就一直提交错误， 但是在本地不用初始化就可以，why
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RowNode {
	 char c;
	 struct RowNode *nextRowNode;
};
struct HeadNode {
	 struct HeadNode *lastHeadNode;
	 struct RowNode *first;
	 struct RowNode *rear;
	 struct HeadNode *nextHeadNode;
};
struct HeadNode* get_head (int headSize) {
	 struct HeadNode* 
		h = (struct HeadNode*)malloc(sizeof(struct HeadNode));
     h->lastHeadNode = h->nextHeadNode = NULL;
     h->first = h->rear = NULL;
	 struct HeadNode *p, *q;
	 q = h;

	 for(int i = 1; i < headSize; ++i) {
		p = (struct HeadNode*)malloc(sizeof(struct HeadNode));
        p->nextHeadNode = NULL;
        p->first = p->rear = NULL;
		p->lastHeadNode = q;
		q->nextHeadNode = p;
		q = p;	  
	 }
	 return h;
}
char* get_new_s (struct HeadNode* head, int size) {
	 char *newS = (char*)malloc(sizeof(char)*size + 1);
	 struct HeadNode* headIndex = head;
	 struct RowNode* p;

	 int i = 0;
	 while (headIndex != NULL) {
		  p = headIndex->first;
		  while (p != NULL ) {
			   newS[i++] = p->c;
			   p = p->nextRowNode;
		  }
		  headIndex = headIndex->nextHeadNode;
	 }
	 free(head);
	 newS[i] = '\0';
	 return newS;
}
char * convert(char * s, int numRows){
	 struct HeadNode *head;
	 struct HeadNode *headIndex;
	 struct RowNode *p;
	 int count_size = 0;

	 if (numRows < 2) return s;

	 head = get_head(numRows);

	 headIndex = head;
	 while (*s != '\0') {
		  while (*s != '\0') {
			   p = (struct RowNode*)malloc(sizeof(struct RowNode));
               p->nextRowNode = NULL;
			   p->c = *s;
			   if (headIndex->first == NULL) {
				    headIndex->first = p;
					headIndex->rear = p;
			   }else {
				    headIndex->rear->nextRowNode = p;
					headIndex->rear = p;
			   }
			   ++count_size;
			   ++s;
			   if (headIndex->nextHeadNode == NULL) {
				   headIndex = headIndex->lastHeadNode;
				   break;
			   }
			   else
		     		headIndex = headIndex->nextHeadNode;			
		  }
		  while (*s != '\0') {
			   p = (struct RowNode*)malloc(sizeof(struct RowNode));
               p->nextRowNode = NULL;
			   p->c = *s;
			   headIndex->rear->nextRowNode = p;
			   headIndex->rear = p;
			   ++s;
			   ++count_size;
			   if (headIndex->lastHeadNode == NULL) {
				    headIndex = headIndex->nextHeadNode;
				    break;
			   }else
				    headIndex = headIndex->lastHeadNode;
		  }
	 }
	 return get_new_s(head, count_size);
} 
/*
int main(){
	char *s = "PAYPALISHIRING";
	s = convert(s, 1);
	printf("%s\n", s);
	return 0;
}	
*/

