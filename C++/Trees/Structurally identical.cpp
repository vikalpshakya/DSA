//   QUES. Given two generic trees, return true if they are structurally identical. Otherwise, return false.
//         Structural Identical
//         If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.  

/*  Time complexity: O(N)   where N is the number of nodes in the smaller tree and
    Space complexity: O(H)  H is the height/depth of the smaller tree  */

   
    bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {

    if( root1->data != root2->data || root1->children.size() != root2->children.size()) return false;
     
    for ( int i = 0; i < root1->children.size() ; i++) {
        if(root1->children[i]->data != root2->children[i]->data)
           return  areIdentical(root1->children[i], root2->children[i]);
    }
    return true;
      
    }
