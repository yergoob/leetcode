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
struct ListNode *mergeTwoLists(struct ListNode *first, struct ListNode *second){
    struct ListNode *head, *tail;

    if(first->val <= second->val){
        head = first;
        first = first->next;
    }
    else{
        head = second;
        second = second->next;
    }
    tail = head;
    while(first != NULL && second != NULL){
        if(first->val <= second->val){
            tail->next = first;
            first = first->next;
        }else{
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }
    if(first != NULL)
        tail->next = first;
    if(second != NULL)
        tail->next = second;

    return head;
}
void iterate_lists(struct ListNode** lists, int size){
    if(size == 1)
        return;

    /* 迭代前做一个输出
    printf("迭代前做一个输出 size == %d \n", size);
    struct ListNode *q;
    for(int i = 0; i < size; ++i){
        q = lists[i];
        while(q != NULL){
            printf("%d,", q->val);
            q = q->next;
        }
        printf("\n");
    }
*/
    for(int i = 0; i < size; i=i+2){
        if((i+1) < size){
            if(lists[i] == NULL && lists[i+1] == NULL){
                lists[i/2] = NULL;  // 之前通过93/133的错误出在这里，就是没有两个都是空的没做空处理
                continue;
            }
            else if(lists[i] == NULL){
                lists[i/2] = lists[i+1];
            }else if(lists[i+1] == NULL){
                lists[i/2] = lists[i];
            }else{
                lists[i/2] =  mergeTwoLists(lists[i], lists[i+1]);
            }
        }else{
            lists[i/2] = lists[i];
        }
    }
    if((size % 2) == 1)// 为了折半
        ++size;
    size /= 2;
    iterate_lists(lists, size);
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return NULL;

    iterate_lists(lists, listsSize);
    return lists[0];
}

int main(){
/*  93 / 133 个通过的测试用例
    int l[3][3] = {
            {1,4,5},
            {1,3,4},
            {2,6}
    };
    int listsSize = 3;
    int lists_i_Size = 3;
    struct ListNode** lists = malloc(listsSize*sizeof(struct ListNode*));
    struct ListNode *p, *h, *q;

    for(int i = 0; i < listsSize; ++i){
        h = NULL;
        for(int j = 0; j < lists_i_Size; ++j){
            if(l[i][j] != 0){
                p = malloc(sizeof(struct ListNode));
                p->val = l[i][j];
                p->next = NULL;
                if(h == NULL){
                    h = p;
                    q = h;
                }else {
                    q->next = p;
                    q = q->next;
                }
            }
        }
        lists[i] = h;
    }
*/
    /* 这个例子不通过， 超出时间此限制
     * [[0,1,2],[-10,-8,-5,-4],[],[],[-3],[-10,-9,-6,-4,-3,-2,-2,-1,2],[-9,-9,-2,-1,0,1],[-9,-4,-3,-2,2,2,3,3,4]]
     *  下面测试一下出错的例子
     */
    int l[8][10] = {
            {0,1,2,100},
            {-10,-8,-5,-4,100},
            {100},
            {100},
            {-3,100},
            {-10,-9,-6,-4,-3,-2,-2,-1,2,100},
            {-9,-9,-2,-1,0,1,100},
            {-9,-4,-3,-2,2,2,3,3,4,100}
    };
    int listsSize = 8;
    int lists_i_Size = 10;
    struct ListNode** lists = malloc(listsSize*sizeof(struct ListNode*));
    struct ListNode *p, *h, *q;

    for(int i = 0; i < listsSize; ++i){
        if(i == 2 || i == 3){
            lists[i] = NULL;
            continue;
        }
        h = NULL;
        for(int j = 0; j < lists_i_Size; ++j) {
            if(l[i][j] == 100){
                break;
            }else{
                p = malloc(sizeof(struct ListNode));
                p->val = l[i][j];
                p->next = NULL;
                if(h == NULL){
                    h = p;
                    q = h;
                }else{
                    q->next = p;
                    q = p;
                }
            }
        }
        lists[i] = h;
    }
/*
    for(int i = 0; i < listsSize; ++i){
        q = lists[i];
        while(q != NULL){
            printf("%d,", q->val);
            q = q->next;
        }
        printf("\n");
    }
*/
    struct ListNode* ret = mergeKLists(lists,listsSize);
    while(ret != NULL){
        printf("%d,", ret->val);
        ret = ret->next;
    }
    printf("\n");
    return 0;
}