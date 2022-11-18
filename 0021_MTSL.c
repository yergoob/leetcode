#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INDEX_MAP 100
#define MAX_LEN   201
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ArrayList {
	struct ListNode *FirstNode;
};
void get_ArrayList(struct ListNode* l, struct ArrayList *arrl){
	struct ListNode *p;
	int i;

	while(l != NULL){
		i = l->val + INDEX_MAP;
		p = arrl[i].FirstNode;
		if(p != NULL){
			while(p->next != NULL){
				p = p->next;
			}
			p->next = l;
			p = p->next;
		}else{
			arrl[i].FirstNode = l;
			p = l;
		}
		l = l->next;
		p->next = NULL;
	}
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	int i;
	if(list1 == NULL && list2 == NULL)
		return NULL;
		
	struct ArrayList arrl[MAX_LEN];
	memset(arrl,0,sizeof(struct ArrayList)*MAX_LEN);
	
	get_ArrayList(list1, arrl);
	get_ArrayList(list2, arrl);

	struct ListNode *p = NULL,*head = NULL;
	for(i = 0; i < MAX_LEN; ++i){
		if(arrl[i].FirstNode != NULL){
			if(head == NULL){
				head = arrl[i].FirstNode;	
				p = head;
			}else{
				while(p->next != NULL){
					p = p->next;
				}
				p->next = arrl[i].FirstNode;
			}
		}
	}
			
	return head;
}
