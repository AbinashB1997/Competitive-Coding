// Reversing the level order traversal, that means, for now, we have to traverse from the last level to the first
void printReverse(Node * root)
{
	if(!root) {
		return;
	}
	queue<Node *>q;
	vector<int>NodeList;
	q.push(root);
	while(!q.empty())
	{
		Node * node = q.front();
		q.pop();
		NodeList.push_back(node->data);
		if(node->right) {
			q.push(node->right);
		}
		if(node->left) {
			q.push(node->left);
		}
	}
	std::reverse(NodeList.begin(), NodeList.end());
	for(int i : NodeList) {
		cout << i << ' ';
	}
}