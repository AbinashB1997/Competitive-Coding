// Left and Right View of a binary tree
void PrintLeft(Node * root, int currLevel, int * PrevLevel)
{
	if(!root) {
		return;
	}
	if(*PrevLevel < currLevel) {
		cout << root->data << ' ';
		*PrevLevel = currLevel;
	}
	PrintLeft(root->left, currLevel + 1, PrevLevel);//For Right view call Right side recursively, then do the same for left.
	PrintLeft(root->right, currLevel + 1, PrevLevel);
}
void printit(Node *root)
{
	int PrevLevel = 0; 
	PrintLeft(root, 1, &PrevLevel);
}