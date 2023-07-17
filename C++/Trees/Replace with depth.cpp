//     Ques.   You are given a generic tree. You have to replace each node with its depth value. 
//             You just have to update the data of each node, there is no need to return or print anything.




void replaceWithDepthValue_helper(TreeNode<int>* root, int depth) {
    
    root->data = depth;
    for( int i =0 ; i< root->children.size() ; i++) {       
        replaceWithDepthValue_helper(root->children[i], depth+1);
    }
}

void replaceWithDepthValue(TreeNode<int>* root) {
    replaceWithDepthValue_helper(root, 0);
}
