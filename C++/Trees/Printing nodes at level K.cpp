// time O(n) , space O(h)  //

void printAtLevelK(TreeNode<int>*root , int k){
    if(root==NULL) return ;   // edge case 
    if(k==1){
        cout << root->data << endl; // base case
        return;
    }
    for( int i = 0; i < root->children.size() ; i++){
        printAtLevelK(root->children[i]);
    }
}
