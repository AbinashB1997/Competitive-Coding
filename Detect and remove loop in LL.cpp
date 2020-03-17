/*
	Detect and remove loop in LL
*/

ListNode* Solution::solve(ListNode* A) {
    if(!A) {
        return NULL;
    }
    ListNode * slow = A, * fast = A;
    slow = slow->next, fast = fast->next->next;
    while(fast and fast->next) {
        if(slow == fast) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow != fast) {
        return A;
    }
    slow = A;
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return A;
}