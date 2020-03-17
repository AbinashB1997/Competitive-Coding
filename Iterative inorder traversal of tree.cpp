/*
	Iterative code for inorder traversal
*/
vector<int> inorderTraversal(TreeNode* A) {
    stack<TreeNode *> stk;
    TreeNode * curr = A;
    vector<int> ans;
    while (curr or !stk.empty()) { 
        while (curr !=  NULL) { 
            stk.push(curr); 
            curr = curr->left; 
        } 
        curr = stk.top(); 
        stk.pop(); 
        ans.push_back(curr->val); 
        curr = curr->right; 
    }
    return ans;
}