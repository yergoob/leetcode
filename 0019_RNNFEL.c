#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	struct ListNode *p;

	p = head;
	while(--n > 0){
		p = p->next;
	}
	if(p->next != NULL){
		p = p->next;
		struct ListNode *prev = head;
		while(p->next != NULL){
			p = p->next;
			prev = prev->next;
		}
		prev->next = prev->next->next;
	}else{//p已经走了n个 要删除的是第一个节点
		head = head->next;
	}
	return head;
}


