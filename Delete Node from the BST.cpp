Node * InorderSuccessor(Node * root) {
    while(root->left != NULL) root = root->left;
    return root;
}

Node * deleteNode(Node *root,  int x)
{
    if(!root) {
        return root;
    }
    if(x > root->data) {
        root->right = deleteNode(root->right, x);
    }else if(x < root->data) {
        root->left = deleteNode(root->left, x);
    }else {
        if(!root->right) {
            Node * temp = root->left;
            delete(root);
            return temp;
        }else if(!root->left) {
            Node * temp = root->right;
            delete(root);
            return temp;
        }else {
            Node* temp = InorderSuccessor(root->right); 
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
}