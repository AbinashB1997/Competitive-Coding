/*
	Vertical Order Traversal
	Link: https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
*/

void verticalTraversal(TreeNode * A, map<int, vector<int>> &Nodes) {
    if(!A) {
        return;
    }
    queue<pair<int, TreeNode *>> Q;
    Q.push(make_pair(0, A));
    while(!Q.empty()) {
        pair<int, TreeNode *> data = Q.front();
        Q.pop();
        Nodes[data.first].push_back((data.second)->val);
        if((data.second)->left) {
            Q.push(make_pair(data.first - 1, (data.second)->left));
        }
        if((data.second)->right) {
            Q.push(make_pair(data.first + 1, (data.second)->right));
        }
    }
}


vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int, vector<int>> mp;
    verticalTraversal(A, mp);
    vector<vector<int>> vec;
    for(auto i : mp) {
        vec.push_back(i.second);
    }
    return vec;
}