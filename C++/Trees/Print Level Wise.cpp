/*
 Time complexity: O(N)
 Space complexity: O(M)
 where N is the number of nodes in the tree and
 M is the maximum number of nodes in a level
*/

void printLevelWise(TreeNode<int>* root) {
     if(!root)
        return;

    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << ":";
        for(int i=0; i<front->children.size(); i++) {
            pendingNodes.push(front->children[i]);
            if(i == front->children.size()-1)
                cout << front->children[i]->data ;
            else    
                cout << front->children[i]->data << ",";
        }
        cout << endl;
    }
}
