/*
	Detect loop in singly LL
*/

int detectloop(Node *head) {
    
    Node * slow = head, *fast = head;
    slow = slow->next, fast = fast->next->next;
    while(fast and fast->next) {
        if(slow == fast) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(slow != fast) {
        return 0;
    }else {
        return 1;
    }
}