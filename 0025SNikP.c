/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 时间8 ms 击败 75.32%    内存7.1 MB 击败 17.12%
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseKOne(struct ListNode *GH, int k){
    struct ListNode **listsK = malloc(k*sizeof(struct ListNode*));
    struct ListNode *p, *ret;

    int i;
    p = GH->next;
    for(i = 0; i < k; ++i){
        if(p != NULL){
            listsK[i] = p;
            p = p->next;
        }else{
            break;
        }
    }
    if(i < k){
        ret = listsK[i-1];
    }else{
        --i;
        ret = listsK[0];
        listsK[0]->next = listsK[i]->next;
        GH->next = listsK[i];
        for(; i > 0; --i){
            listsK[i]->next = listsK[i-1];
        }
    }

    return ret;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(head == NULL || head->next == NULL || k ==1)
        return head;

    struct ListNode *GroupHead, dummy, *p;
    GroupHead = &dummy;
    GroupHead->next = head;

    for(int i = 1; i < k; ++i) {
        head = head->next;
    }

    GroupHead =  reverseKOne(GroupHead,k);
    while(GroupHead->next != NULL){
        GroupHead = reverseKOne(GroupHead, k);
    }

    return head;
}
int main(){
    int array[] = {1,2,3,4,5};
    struct ListNode *head, *p, *q;
    head = NULL;
    for(int i = 0; i < 5; ++i){
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
    head = reverseKGroup(head, 2);
    while(head != NULL){
        printf("%d,", head->val);
        head = head->next;
    }
    return 0;
}