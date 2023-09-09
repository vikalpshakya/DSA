//     Time complexity: O(N)
//     Space complexity: O(N)

int numNodes(BinaryTreeNode<int>* root) {
  if ( root == NULL ) return 0;
  return 1 + numNodes(root->left) + numNodes(root->right) ;

 

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
