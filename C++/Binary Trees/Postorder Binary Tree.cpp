//     Time complexity: O(N)
//     Space complexity: O(H)

void postOrder(BinaryTreeNode<int> *root) {
	if ( root == nullptr) return;
	
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
	
}
/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
***********************************************************/
