//  QUES:  For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.

//     Time complexity: O(N)
//     Space complexity: O(N) 


bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if( root == NULL) return false;
    if( root->data == x) return true ;
    return isNodePresent(root->left,  x) || isNodePresent(root->right, x) ;
}


