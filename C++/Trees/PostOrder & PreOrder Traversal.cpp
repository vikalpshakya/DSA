// ------Post Order Traversal --------//

void printPostOrder(TreeNode<int>* root) {
    if( root == NULL) return ;
    for ( int i = 0 ; i < root->children.size(); i++){
        printPostOrder(root->children[i]);
    }
    cout << root->data<<" ";
}

// ---------Pre Order Traversal --------- //

void printPreOrder(TreeNode<int>*root){
    if(root == nullptr) return;
    cout << root->data << " ";
    for ( int i = 0 ; i < root->children.size(); i++){
            printPreOrder(root->children[i]);  
    }
}
