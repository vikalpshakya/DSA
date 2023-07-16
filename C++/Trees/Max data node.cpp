// --------Iterative approach---------//
    // Time complexity: O(N)
    // Space complexity: O(1)

TreeNode<int>* maxDataNode_iterative(TreeNode<int>* root) {

    int max = root->data;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size()) {
      TreeNode<int>* front  = pendingNodes.front();
      pendingNodes.pop();

      for (int i = 0; i < front->children.size(); i++) {
        pendingNodes.push(front->children[i]);
        if (max < front->children[i]->data)
          max = front->children[i]->data;
      }
    }

    TreeNode<int> *maxNode = new TreeNode<int>(max);
    return maxNode;
}
// --------Recursive Approach ------//

    // Time complexity: O(N)
    // Space complexity: O(H)

TreeNode<int>* maxDataNode_rec(TreeNode<int>* root){
   
    if(root->children.size()==0) return root;
    TreeNode<int>*maxNode = new TreeNode<int>(root->data);
    
    for( int i = 0; i < root->children.size(); i++){
        maxNode->data = max(maxNode->data, maxDataNode_rec(root->children[i])->data);
    }
    return maxNode;
}
// -----------Main---------//
TreeNode<int>* maxDataNode(TreeNode<int>* root){
    return maxDataNode_rec(root);
}









