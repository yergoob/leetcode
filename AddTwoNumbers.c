
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* new_list;
    struct ListNode* p;
	int jinwei = 0;

	new_list = l1;
	while(l1 != NULL && l2 != NULL){
		p = l1;
		l1->val += (l2->val + jinwei);
		jinwei = 0;
		if (l1->val >= 10){
			jinwei = 1;
			l1->val -= 10;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
		
	if (l1 == NULL && l2 == NULL){
		if (jinwei == 1){
			p->next = malloc(sizeof(struct ListNode));
            p->next->val = 1;
            p->next->next = NULL;
            jinwei = 0;
		}
	}else if (l1 == NULL){
		p->next = l2;
		l1 = p->next;
	}

	if(jinwei == 1){
		do{
			l1->val += jinwei;
			jinwei = 0;
			if(l1->val >= 10){
				jinwei = 1;
				l1->val -= 10;
			}
            p = l1;
			l1 = l1->next;
		}while(jinwei == 1 && l1 != NULL);
	}

	if(jinwei == 1 && l1 == NULL){
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p = p->next;
        p->val = 1;
		p->next = NULL;
	}
    return new_list;
}




