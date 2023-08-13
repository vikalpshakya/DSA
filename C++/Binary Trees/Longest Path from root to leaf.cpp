// Time complexity O(N) 
// Space complexity O(H)

vector<int>* longestPath(BinaryTreeNode<int>* root) {
    if( !root) return NULL;
    if( root->left == NULL && root->right == NULL) {
        vector<int>*output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>*leftPath = longestPath(root->left);
    vector<int>*rightPath = longestPath(root->right);
    if (leftPath == NULL && rightPath  ){ 
        rightPath->push_back(root->data);
        return rightPath;
    }
    else if(leftPath && !rightPath){
        leftPath->push_back(root->data);
        return leftPath;
    }
    else if(leftPath&&rightPath){
        if(leftPath->size() > rightPath->size()){
        leftPath->push_back(root->data);
        delete rightPath;
        return leftPath;
        } else if (leftPath->size() < rightPath->size()) {
        rightPath->push_back(root->data);
        delete leftPath;
        return rightPath;
        }
    }
}
