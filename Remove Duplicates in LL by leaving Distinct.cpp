/*
	Remove Duplicates from Sorted List II
	Link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/
*/

void insertNode(ListNode ** head, int x, ListNode ** first) {
    if(!(*head)) {
        (*head) = new ListNode(x);
        *first = (*head);
    }else {
        (*head)->next = new ListNode(x);
        (*head) = (*head)->next;
    }
}

ListNode* Solution::deleteDuplicates(ListNode* A) {
    map<int, int> freq;
    ListNode * ptr = A;
    while(ptr) {
        freq[ptr->val]++;
        ptr = ptr->next;
    }
    ListNode * head = NULL;
    ListNode * first = NULL;
    for(auto I : freq) {
        if(I.second == 1) {
            insertNode(&head, I.first, &first);
        }
    }
    return first;
}