#include<bits/stdc++.h>
BinaryTreeNode<int>*ancestor(BinaryTreeNode<int>*root , int a , int b){
	if(root == NULL) return root;
	if(root->data == a || root-> data == b) return root;
	BinaryTreeNode<int>*left = ancestor(root->left, a,b  );
	BinaryTreeNode<int>*right = ancestor(root->right, a, b);
	if ( left == NULL ) return right;
	else if(right == NULL ) return left;
	else return NULL;
}

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
	BinaryTreeNode<int>*ans = ancestor(root, a,  b);
	return ans->data;
}
