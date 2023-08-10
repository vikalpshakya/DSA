//     Time complexity O(N^2)
//     Space complexity O(H)

#include<bits/stdc++.h>
bool isBST(BinaryTreeNode<int>*root , int min  , int max ){
	if( !root ) return true;
	if( root->data < min || root->data > max) return false;
	return isBST(root->left , min , root->data) && isBST(root->right, root->data , max ); 
}

int size ( BinaryTreeNode<int>* root) {
	if( !root ) return 0;
	return max(size(root->left), size(root->right) ) +1 ; 
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	if( !root ) return 0;
	if( isBST(root , INT_MIN , INT_MAX)){
		return size(root);
	}
	return max( largestBSTSubtree(root->left) , largestBSTSubtree(root->right));

}
