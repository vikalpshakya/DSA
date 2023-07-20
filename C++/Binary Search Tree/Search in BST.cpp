// Time complexity O(H) , space complexity O(H) [ H is the height of the tree ]

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	if ( root == nullptr) return false;
	if (root->data == k) return true;
	// if(root->data < k )
	// 	searchInBST(root->right,  k);
	// else
	// 	searchInBST(root->left, k);
  return root->data < k ? searchInBST(root->right, k) : searchInBST(root->left,k);
}
