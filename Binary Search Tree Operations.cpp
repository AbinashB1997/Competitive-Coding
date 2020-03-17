#include<bits/stdc++.h>

using namespace std;

typedef struct node {
    int Data;
    node * left;
    node * right;
    node(int val)
    {
        Data = val;
        right = left = NULL;
    }
}node;

std::vector<int>Nodes;

void insert(node ** root, int val)
{
    if(*root == NULL){
        *root = new node(val);
    }
    else if((*root)->Data <= val) {
        insert(&((*root)->right), val);
    }
    else if((*root)->Data > val) {
        insert(&((*root)->left), val);
    }
}

node * getBST(int * arr, int size)
{
    node * root = NULL;
    for(int i = 0; i < size; i++) {
        insert(&root, arr[i]);
    }
    return root;
}

void inOrderTraversal(node * root)
{
    if(root && root->left) {
        inOrderTraversal(root->left);
    }
    if(root){
        cout << root->Data << ' ';
        Nodes.push_back(root->Data);
    }
    if(root && root->right) {
        inOrderTraversal(root->right);
    }
}

void PreOrderTraversal(node * root)
{
    if(root)
    {
        printf("%d\n", root->Data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void postOrderTraversal(node * root)
{
    if(root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d\n", root->Data);
    }
}

node * search(node *root, int key) {
    if(root == NULL || root->Data == key) {
        return root;
    }
    else if(root->Data < key) {
        return search(root->right, key);
    }else {
        return search(root->left, key);
    }
}

node * lca(node* root, int node1, int node2)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->Data > node1 && root->Data > node2) {
        return lca(root->left, node1, node2);
    }
    if (root->Data < node1 && root->Data < node2) {
        return lca(root->right, node1, node2);
    }
    return root;
}

void maxHeap(node * root, vector<int>a, int * starting) {
    if(!root) {
        return;
    }
    maxHeap(root->left, a, starting);
    maxHeap(root->left, a, starting);
    root->Data = a[++(*starting)];
}

int Height(node* root)
{
    if (root == NULL){
        return 0;
    }
    else
    {
        int l = Height(root->left);
        int r = Height(root->right);
        if (l > r)  {
            return(l + 1);
        }
        else {
            return(r + 1);
        }
    }
}

int main()
{
    int N; cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    node * root = getBST(arr, sizeof(arr)/sizeof(int));
    int Q; cin >> Q;
    node * Rt = search(root, Q);
    PreOrderTraversal(Rt);
    /*
    int start = -1;
    maxHeap(root, Nodes, &start);
    postOrderTraversal(root);
    */
    /*
    int node1, node2;
    cin >> node1 >> node2;
    node * currNode = lca(root, node1, node2);
    cout << currNode->Data;
    */
    return 0;
}