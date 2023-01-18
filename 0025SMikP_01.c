/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 时间8 ms 击败 75.32%    内存6.7 MB 击败 96.29%
 */
#include <stdio.h>
#include <stdlib.h>
#define FIRST_GROUP 1
#define NO_FIRST_GROUP 0
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseKOne(struct ListNode *GH, int k){
    struct ListNode *lastNodeNext, *p, *q, *newList, *tail;
    int i;

    // 进来的都够k个,且 k >= 2
    newList = GH->next;
    tail = newList;
    p = newList->next;
    for(i = 1; i < k; ++i){
            q = p;
            p = p->next;
            q->next = newList;
            newList = q;
    }
    GH->next = newList;
    tail->next = p;
    return tail;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(head == NULL || head->next == NULL || k ==1)
        return head;

    int i, flag = FIRST_GROUP;
    struct ListNode *GroupHead, dummy, *p;
    GroupHead = &dummy;
    GroupHead->next = head;

    while(GroupHead->next != NULL){
        p = GroupHead->next;
        for(i = 1; i < k; ++i){
            if(p->next != NULL){
                p = p->next;
            }else
                break;
        }
        if(i < k){
            return head;
        }else{
            if(flag == FIRST_GROUP){
                head = p;
                flag = NO_FIRST_GROUP;
            }
            GroupHead = reverseKOne(GroupHead, k);
        }
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