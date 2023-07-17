//     QUES. Given a tree and an integer x, find and return the number of nodes which contains data greater than x.

int getLargeNodeCount(TreeNode<int>* root, int x) {
    int count = 0;
    if(root->data > x)
        count+=1;
    for( int i =0 ; i < root->children.size() ; i++){
        count+=getLargeNodeCount(root->children[i],x);
    }
    return count ;
}
