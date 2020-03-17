/*
	Check if the complete binary tree contains an index N, Where N ~ 10^18.
*/

#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	Node* left, * right; 
}; 

Node* newNode(int data) 
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 
Node* insertLevelOrder(int arr[], Node* root, int i, int n) 
{ 
	if (i < n) 
	{ 
		Node* temp = newNode(arr[i]); 
		root = temp; 
		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n); 
		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n); 
	} 
	return root; 
} 

void inOrder(Node* root) 
{ 
	if (root != NULL) 
	{ 
		inOrder(root->left); 
		cout << root->data <<" "; 
		inOrder(root->right); 
	} 
} 

string getPath(int index) {
    stack<char> stk;
    while(index != 1) {
        int par = index/2;
        int child1 = 2 * (par);
        int child2 = 2 * (par) + 1;
        //cout << "index " << par << " has child1 = " << child1 << " and child2 = " << child2 << '\n';
        (index == child1) ? stk.push('L') : stk.push('R');
        index /= 2;
    }
    string path = "";
    while(!stk.empty()) {
        path += stk.top();
        stk.pop();
    }
    return path;
}

bool isExist(Node *root, int index) {
    Node * currNode = root;
    string s = getPath(index);
    for(char ch : s) {
        //cout << "I am at index " << currNode->data << '\n';
        if(currNode->data == index) {
            return true;
        }else {
            if(currNode and ch == 'L') {
                currNode = currNode->left;
                if(currNode == NULL) {
                    return false;
                }
            }else if(currNode and ch == 'R') {
                currNode = currNode->right;
                if(currNode == NULL) {
                    return false;
                }
            }else {
                return false;
            }
        }
    }
    return true;
}

int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	Node* root = insertLevelOrder(arr, root, 0, n); 
	//inOrder(root); 
	//cout << getPath(11);
	cout << isExist(root, 1644648);
}