void inorder1(struct node * root, vector<node *> &Nodes) {
    if(root) {
        inorder1(root->left, Nodes);
        Nodes.push_back(root);
        inorder1(root->right, Nodes);
    }
}
void inorder2(struct node * root, vector<node *>Nodes,int node1,int node2) {
    if(root) 
    {
        inorder2(root->left, Nodes, node1, node2);
        if(root->data == node1) {
            root->data = node2;
        }
        else if(root->data == node2) {
            root->data = node1;
        }
        inorder2(root->right, Nodes, node1, node2);
    }
}

struct node *correctBST( struct node* root )
{
    vector<node *>Nodes;
    inorder1(root, Nodes); // It store the nodes in incorrect BST
    vector<node *>copy(Nodes.begin(), Nodes.end());//It actually sort the incorrect tree and store all nodes in copy vector
    sort(copy.begin(), copy.end(), [](node * a, node * b) {
        return a->data < b->data;
    });
    int c, d;
    for(int i = 0;i<copy.size();i++)
    {
        if(Nodes[i]->data!= copy[i]->data)
        {
            c = Nodes[i]->data;
            d = copy[i]->data;
            break;
        }
    }
    inorder2(root, copy, c, d); // This will reswap 2 nodes that are incorrect before.
    return root;
}