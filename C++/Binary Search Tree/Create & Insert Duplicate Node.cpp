    // Time complexity : O(N)
    // Space complexity : O(H)

void insertDuplicateNode(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    
    BinaryTreeNode<int>* leftNode;
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    leftNode=root->left;
    BinaryTreeNode<int>*newNode=new BinaryTreeNode<int>(root->data);
    root->left=newNode;
    root->left->left=leftNode;
    
}
