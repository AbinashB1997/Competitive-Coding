// The boundary of a binary tree

void printLeaf(Node *root) {
	if(root) {
		printLeaf(root->left);
		if(!root->left && !root->right) {
			cout << root->data << ' ';
		}
		printLeaf(root->right);
	}
}

void printRightBoundary(Node *root)
{
	if(root) {
		if(root->right) {
			printRightBoundary(root->right);
			cout << root->data << ' ';
		} else if(root->left) {
			printRightBoundary(root->left);
			cout << root->data << ' ';
		} else {
			return;
		}
	}
}

void printLeftBoundary(Node *root)
{
	if(root) {
		if(root->left) {
			cout << root->data << ' ';
			printLeftBoundary(root->left);
		} else if(root->right) {
			cout << root->data << ' ';
			printLeftBoundary(root->right);
		} else {
			return;
		}
	}
}

void printBoundary(Node *root) 
{
	if(root) {
		cout << root->data << ' '; // It only print the root
		printLeftBoundary(root->left);
		printLeaf(root->left);
		printLeaf(root->right);
		printRightBoundary(root->right);
	}
}