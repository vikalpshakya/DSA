//    Time complexity: O(N)
//    Space complexity: O(H)

#include<bits/stdc++.h>

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	pair<int,int> minMax ;
	if( root==nullptr)  {
		minMax.first = INT_MAX;
		minMax.second = INT_MIN;
		return minMax;
	}
	pair<int, int> leftPair = getMinAndMax(root->left);
	pair<int, int> rightPair = getMinAndMax(root->right);
	
    minMax.first = min(min(leftPair.first, rightPair.first), root->data);
	minMax.second = max(max(leftPair.second, rightPair.second), root->data);
		return minMax;
}
