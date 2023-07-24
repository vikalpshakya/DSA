//-- Time complexity O(n^2) space complexity O(n) -//

#include<bits/stdc++.h>
int maximum(BinaryTreeNode<int>*root) {
	if(!root) return INT_MIN;
	return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(BinaryTreeNode<int>*root) {
	if(!root) return INT_MAX;
	return min(root->data,min(minimum(root->left),minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) {
	if(root==nullptr) return true;
	int leftMax = maximum(root->left);
	int rightMax = minimum(root->right);
        if (root->data > leftMax && root->data <= rightMax &&isBST(root->left) && isBST(root->right)) return true;
          return false;
}
