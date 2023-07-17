// Deleting nodes manually using post-order traversal //

void deleteTree (TreeNode<int>* root) {
  if ( root == NULL ) return ;
  for( int i = 0 ; i < root->children.size(); i++) {
      deleteTree ( root->chilren[i] ); 
    }
  delete root;
}

// ----------using destructor-----------//

//--- After using this destructor in out TreeNode class , we just simple write " delete node ; " in our main function to delete the whole tree---- //

// This is TreeNode class //

  template <typename T>
  class TreeNode {
   public:
      T data;
      vector<TreeNode<T>*> children;
  
      TreeNode(T data) {
          this->data = data;
      }
  // Calling destructor for deletion // 
      ~TreeNode() {
          for (int i = 0; i < children.size(); i++) {
              delete children[i];
          }
      }
    };














