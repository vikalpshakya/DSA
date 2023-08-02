/*    Time complexity: O(H)
    Space complexity: O(H)
    where H is the height of the input BST    */

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	if(!root) return NULL;

	if (root->data == data) {
		vector<int>*ans = new vector<int>();
		ans->push_back(root->data);
		return ans;
	}	

	vector<int>*left =  getPath(root->left,data);
	if(left != NULL) {
		left->push_back(root->data);
		return left;
	}

	vector<int>*right = getPath(root->right, data);
        if (left == NULL && right != NULL) {
                right->push_back(root->data);
                return right;
        }
}
