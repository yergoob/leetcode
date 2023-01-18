/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode *before_adj1, *adj1, *adj2, dummy;

    before_adj1 = &dummy;
    before_adj1->next = head;
    adj1 = before_adj1->next;
    adj2 = adj1->next;
    head = adj2;
    while(adj1 != NULL && adj2 != NULL){
        before_adj1->next = adj2;
        adj1->next = adj2->next;
        adj2->next = adj1;

        before_adj1 = adj1;
        adj1 = before_adj1->next;
        if(adj1 != NULL)
            adj2 = adj1->next;
    }
    return head;
}
int main(){
    int array[] = {1,2,3,4};
    struct ListNode *head, *p, *q;
    head = NULL;
    for(int i = 0; i < 4; ++i){
        p = malloc(sizeof(struct ListNode));
        p->val = array[i];
        p->next = NULL;
        if(head == NULL){
            head = p;
            q = head;
        }else{
            q->next = p;
            q = q->next;
        }
    }
    head = swapPairs(head);
    while(head != NULL){
        printf("%d,", head->val);
        head = head->next;
    }
    return 0;
}