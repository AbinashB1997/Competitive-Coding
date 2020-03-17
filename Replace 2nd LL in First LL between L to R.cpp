/*
Given heads A and B of two linked lists L1 and L2 respectively and given 2 integers C and D such that 0≤C≤D. You have to replace L1[C,D] with L2 (including both indices C and D) and return the resultant list. Note:
Index starts from 0.
D < total number of elements in L1.
You can only use constant amount of extra memory.
Example
L1 = 1->7->3->9->2->8->1->End. L2 = 3->1->9->8->5->End. C=2 D=4 Resultant list L = 1->7->3->1->9->8->5->8->1->End.
*/

ListNode* Solution::solve(ListNode* A, ListNode* B, int C, int D) {
    if(!A or !B) {
        return NULL;
    }

    if(C == 0) {
        ListNode * ptr1 = B, * ptr2 = A;
        for(int i = 0; i <= D; i++) {
            ptr2 = ptr2->next;
        }
        while(ptr1->next) {
            ptr1 = ptr1->next;
        }
        ptr1->next = ptr2;
        return B;
    }
    ListNode * ptr1 = A;
    for(int i = 0; i < C - 1; i++) {
        ptr1 = ptr1->next;
    }
    ListNode * ptr2 = A;
    for(int i = 0; i <= D; i++) {
        ptr2 = ptr2->next;
    }
    ptr1->next = B;
    ListNode * ptr3 = A;
    while(ptr3->next) {
        ptr3 = ptr3->next;
    }
    ptr3->next = ptr2;
    return A;
}