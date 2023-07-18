//    Time complexity: O(N)
//    Space complexity: O(N)

int height(BinaryTreeNode<int>* root) {
    if ( root == NULL) return 0;
  
	int leftDepth = height(root->left);
	int rightDepth = height(root->right);
  
	return 1 + max(leftDepth , rightDepth) ;
}
