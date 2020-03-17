/*
	Flatten a 2D Linked List.
	1. The Given LL contains 2 special pointers(next, and down).
	2. LL is sorted horizontally as well as vertically downword in increasing order.
	3. Need to make it inplace sorted singly LL.

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45

	5->7->8->10->19->20->22->28->30->35->40->45->50

*/

Node *mergeLL(Node *a, Node *b) {
    if(!a) {
        return b;
    }
    if(!b) {
        return a;
    }
    Node *ptr = NULL;
    if(a->data <= b->data) {
        ptr = a;
        ptr->bottom = mergeLL(a->bottom, b);
    }else if(b->data <= a->data) {
        ptr = b;
        ptr->bottom = mergeLL(a, b->bottom);
    }
    return ptr;
}

Node *flattenLL(Node * root) {
    if(root) {
        return mergeLL(root, flattenLL(root->next)); // Merge the right list with the already flatten LL.
    }
}

Node *flatten(Node *root)
{
   return flattenLL(root);
}