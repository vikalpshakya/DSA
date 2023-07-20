    // Time complexity: O(N)
    // Space complexity: O(H)

int height(BinaryTreeNode<int>*root){
      if(root==NULL) return 0;
    return max(height(root->left) , height(root->right))+1;

}
BinaryTreeNode<int>*removeLeafNodes(BinaryTreeNode<int>*root){
    if(root==NULL) return NULL;
    if(height(root)==1){
        delete root;
        return NULL;
    }
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;
}

