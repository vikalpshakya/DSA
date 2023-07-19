//    Time complexity: O(N)
//    Space complexity: O(H)


int getSum(BinaryTreeNode<int>* root) {
    if (!root) return 0; // base case 
	  int  leftSum =  getSum(root->left) ;
    int rightSum =  getSum(root->right) ;
  
    return leftSum + rightSum + root->data ;
}
