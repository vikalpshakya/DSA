/*    Time complexity: O(N)
      Space complexity: O(H)      */

void inOrderTraversal(BinaryTreeNode<int>*root ,vector<int>&ans){
	if(!root) return;
	inOrderTraversal(root->left, ans);
	ans.push_back(root->data);
	inOrderTraversal(root->right, ans);
	// InOrder traversal always gives sorted form of BST
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	vector<int>ans;
	inOrderTraversal(root, ans);
	if (ans.empty()) return nullptr;
	Node<int> *newHead = new Node<int>(ans[0]);
	Node<int> *curr = newHead;
	for ( int i = 1; i < ans.size() ; i++) { 
		Node<int>* newNodes = new Node<int>(ans[i]);
		curr->next = newNodes;
		curr = curr->next;
	}
	curr->next= NULL;
	return newHead;
}
