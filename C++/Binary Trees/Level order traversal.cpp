    // Time complexity: O(N)
    // Space complexity: O(N)

void printLevelWise(BinaryTreeNode<int> *root) {
    if( root == nullptr ) return ;
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(nullptr);
        while (!q.empty()) { 
          BinaryTreeNode<int> *node = q.front();
          q.pop();
          if (node == nullptr) { // if one full level is completely traversed
            cout << endl;

		  if (!q.empty())  // if queue has still some elements left 
			q.push(nullptr); 

          } 
		  else {
            cout << node->data << " ";
            if (node->left != NULL)
              q.push(node->left);

            if (node->right)
              q.push(node->right);
          }
        }
}
