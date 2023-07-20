    // Time complexity : O(N)
    // Space complexity : O(H)

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(!root) return ;
    if(root->left==nullptr&&root->right!=nullptr) cout << root->right->data<<" ";
    if(root->right==nullptr&&root->left!=nullptr) cout << root->left->data<<" "; 
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}
