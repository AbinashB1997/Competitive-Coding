/*
	Reverse Nodes in k - groups. 
	Refer to: https://www.interviewbit.com/problems/k-reverse-linked-list/ 
*/
ListNode * reverseList(ListNode* A, int B) {
    ListNode * start = A, * end = NULL, * prev = NULL;
    int count = 0;
    while(count != B) {
        end = start->next;
        start->next = prev;
        prev = start;
        start = end;
        count++;
    }
    if(end) {
        A->next = reverseList(end, B); // It actually add the beginning of the reversed LL to A->next and so on. Then return 
    }                                  // the prev, which actually contains the starting point of revered LL.
    return prev;
}