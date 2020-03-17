/*
	Convert binary tree to circular doubly LL
*/
void convertDoublyCircular(TreeNode * root, TreeNode ** start, TreeNode ** prev) {
    if(root) {
        convertDoublyCircular(root->left, &(*start), &(*prev));
        if(!(*start)) {
            *start = new TreeNode(root->val);
            *prev = *start;
        }else {
            TreeNode * end = new TreeNode(root->val);
            (*prev)->right = end;
            end->left = *prev;
            *prev = end;
        }
        convertDoublyCircular(root->right, &(*start), &(*prev));
    }
}

TreeNode* solve(TreeNode *A){
    if(!A) {
        return NULL;
    }
    TreeNode * start = NULL, * prev = NULL;
    convertDoublyCircular(A, &start, &prev);
    start->left = prev;
    prev->right = start;
    return start;
}