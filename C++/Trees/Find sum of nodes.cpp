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
 // Time complexity O(n) space O(H) 

int sumOfNodes(TreeNode<int>* root) {
    if(!root) return 0;
    int ans = root->data;
    for( int i = 0; i < root->children.size(); i++){
        ans+=sumOfNodes(root->children[i]);
    }
    return ans;
}






