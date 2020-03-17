/*
	Partition in LL such that all nodes less than x will be in left side and all greater nodes in right side(In the order of 
    their presence.
*/
ListNode * first, *second;

void insertNode1(ListNode ** head1, int val) {
    if(!(*head1)) {
        (*head1) = new ListNode(val);
        first = (*head1);
    }else {
        (*head1)->next = new ListNode(val);
        (*head1) = (*head1)->next;
    }
}

void insertNode2(ListNode ** head2, int val) {
    if(!(*head2)) {
        (*head2) = new ListNode(val);
        second = (*head2);
    }else {
        (*head2)->next = new ListNode(val);
        (*head2) = (*head2)->next;
    }
}
 
ListNode* Solution::partition(ListNode* A, int B) {
    if(!A) {
        return NULL;
    }
    if(!A->next) {
        return A;
    }
    ListNode * head1 = NULL, *head2 = NULL;
    int count1 = 0, count2 = 0;
    while(A) {
        if(A->val >= B) {
            count2++;
            insertNode2(&head2, A->val);
        }else {
            count1++;
            insertNode1(&head1, A->val);
        }
        A = A->next;
    }
    if(count1 == 0) {
        return second;
    }
    if(count2 == 0) {
        return first;
    }
    ListNode * ptr = first;
    while(ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = second;
    return first;
}