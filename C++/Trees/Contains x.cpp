//    QUES. Given a generic tree and an integer x, check if x is present in the given tree or not.
//         Return true if x is present, return false otherwise.

bool isPresent(TreeNode<int>* root, int x) {
    if(!root) return false;
    if(root->data == x) return true;

    for(int i =0 ; i < root->children.size(); i++){
         if(isPresent(root->children[i],  x))
            return true;
    }
    return false ;
}
