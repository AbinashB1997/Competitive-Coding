/*
	Detect the initial node from where the loop is encountered. If loop doesn't exist return NULL.
    Qn Link: https://www.interviewbit.com/problems/list-cycle/
*/
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode * slow = A, *fast = A;
    slow = slow->next;
    fast = fast->next->next;
    while(fast and fast->next) {
        if(slow == fast) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow != fast) {
        return NULL;
    }
    slow = A;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}