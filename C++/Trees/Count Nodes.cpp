// Time complexity O(n) ; space O(n)  

int numNodes(TreeNode<int>*root){
    if(root==NULL) return 0;
    int ans = 1;  // length of main root = 1
    for( int i = 0; i < root->children.size(); i++){
        ans += numsNodes(root->children[i]); // recursion will find the number of nodes in the children nodes
    }
    return ans;
}
