Node *convertToDLL(Node *root, Node **head_ref)
{
    if(!root->left && !root->right) {
        root->right = (*head_ref);
        if((*head_ref)) {
            (*head_ref)->left = root;
        }
        (*head_ref) = root;
        return NULL;
    }
    root->right = convertToDLL(root->right, head_ref);
    root->left = convertToDLL(root->left, head_ref);
    return (*head_ref);
}