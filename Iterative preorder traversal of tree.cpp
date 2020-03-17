/*
	Iterative preorder traversal of tree
*/
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
	if (root == NULL) {
       return ans;
	}
    stack<TreeNode *> stk; 
    stk.push(root); 
    while (!stk.empty()) 
    { 
        TreeNode * node = stk.top(); 
        ans.push_back(node->data)); 
        stk.pop(); 
        // Push right and left children of the popped node to stack 
        if (node->right) {
            stk.push(node->right); 
		}
        if (node->left) {
            stk.push(node->left); 
		}
    } 
	return ans;
}