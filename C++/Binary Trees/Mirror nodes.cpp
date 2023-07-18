//  Time complexity: O(N)
//    Space complexity: O(H)


void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if( root == nullptr) return;
	
  	mirrorBinaryTree(root->left);
  	mirrorBinaryTree(root->right);
  	swap(root->left , root->right);
	
}
