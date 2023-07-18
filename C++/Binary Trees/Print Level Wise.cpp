//     Time complexity: O(N)
//     Space complexity: O(N)

void printLevelWise(BinaryTreeNode<int> *root) {
	if(root == NULL) return;
    
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
   
    while(!pendingNodes.empty()){
        
        BinaryTreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        
        if(front->left != NULL){
            pendingNodes.push(front->left);
            cout << "L:" << front->left->data << ",";
        }else{
            cout< < "L:" << -1 << ",";
        }
            
        if(front->right != NULL){
            pendingNodes.push(front->right);
            cout << "R:" << front->right->data;
        }else{
            cout << "R:" << -1;
        }     
        cout << endl;
    }  
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





























