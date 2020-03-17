/*
	Zig - Zag traversal of binary tree
*/
vector<vector<int> > zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(!A) {
        return ans;
    }
    queue<TreeNode *> Q;
    Q.push(A);
    int i = 0;
    while(!Q.empty()) {
        vector<int> temp;
        int NodeCount = Q.size();
        while(NodeCount > 0) {
            TreeNode * curr = Q.front();
            Q.pop();
            temp.push_back(curr->val);
            if(curr->left) {
                Q.push(curr->left);
            }
            if(curr->right) {
                Q.push(curr->right);
            }
            NodeCount--;
        }
        if(i & 1) {
            reverse(temp.begin(), temp.end());
        }
        ans.push_back(temp);
        temp.clear();
        i++;
    }
    return ans;
}