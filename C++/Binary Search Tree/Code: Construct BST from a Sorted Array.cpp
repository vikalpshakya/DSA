//     Time complexity: O(N)
//     Space complexity: O(N)


BinaryTreeNode<int> *constructTree_helper(int *input, int start , int end) { 
	if(start > end) return nullptr;
	int mid = (start+end)/2;
	BinaryTreeNode<int>* newHead = new BinaryTreeNode<int>(input[mid]);
	BinaryTreeNode<int>* left = constructTree_helper(input,  start,  mid-1);
	BinaryTreeNode<int>* right = constructTree_helper(input, mid+1,  end);
	newHead->left = left;
	newHead->right = right;
	return newHead;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	int start = 0;
	return constructTree_helper(input,  start, n-1);
}
