 // Time complexity: O(N)
 // Space complexity: O(H)

int getLeafNodeCount(TreeNode<int>* root) {
    if(root == nullptr) return 0;
    if(root->children.size()==0) return 1;
    int number = 0;
    for( int i = 0 ; i < root->children.size() ; i++){
        number+=getLeafNodeCount(root->children[i]);
    }
    return number;
}

/************************************************************
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
************************************************************/
