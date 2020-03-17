/*
	Iterative code for post order traversal of tree
*/

vector<int> postorderTraversal(TreeNode* A) {
    stack<pair<TreeNode*, bool>> st;
    vector<int> ans;
    if(A->val == -1) {
        return ans;
    }
    st.push(make_pair(A, false));
    while(!st.empty()) {
        pair<TreeNode*, bool> t = st.top();
        if(t.second) {
            ans.push_back((t.first)->val);
            st.pop();
        }else {
            (st.top()).second =true;
            if((t.first)->right) {
                st.push(make_pair((t.first)->right, false));
            }
            if((t.first)->left) {
                st.push(make_pair((t.first)->left, false));
            }
        }
    }
    return ans;
}