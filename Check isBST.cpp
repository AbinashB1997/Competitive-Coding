bool PleaseTell(Node *root, Node *l = NULL, Node *r = NULL)
{
    if(root == NULL) {
        return true;
    }
    if(l != NULL && root->data < l->data) {
        return false;
    }
    if(r != NULL && root->data > r->data) {
        return false;
    }
    return PleaseTell(root->left, l, root) and PleaseTell(root->right, root, r);
}
 
bool isBST(Node* node) {
  return PleaseTell(node, nullptr, nullptr);
}