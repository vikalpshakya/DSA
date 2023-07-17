// Time O(n) , space O(H)  // 

int getHeight(TreeNode<int>* root) {
    int height = 0;
    if(!root) return height;
    for(int i = 0 ; i < root->children.size(); i++){
        int maxHeight = getHeight(root->children[i]);
        if(height < maxHeight)
            height = maxHeight;
    }
    return 1 + height;
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
