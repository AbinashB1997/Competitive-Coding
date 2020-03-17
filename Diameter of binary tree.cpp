pair<int, int> heightDiameter(Node * root) 
{
    if(!root) {
        return make_pair(0, 0);
    }
    
    pair<int, int> Left = heightDiameter(root->left);
    pair<int, int>Right = heightDiameter(root->right);
    
    int Height = 1 + max(Left.first, Right.first);
    int diameter = max(Left.first + Right.first, max(Left.second,Right.second));
    
    return make_pair(Height, diameter);
}