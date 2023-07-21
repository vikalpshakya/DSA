/*
    Time complexity: O(N)
    Space complexity: O(H)

    where N is the number of nodes in the input BST and 
    H is the height of the input BST
*/

//     Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
//     Print the elements in increasing order.


void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if (!root) return;
		// In-order traversal
	elementsInRangeK1K2(root->left, k1, k2);
	if (root->data >= k1 && root->data <= k2) {
		cout << root->data << " ";
	}
	elementsInRangeK1K2(root->right, k1,k2);
}
        
