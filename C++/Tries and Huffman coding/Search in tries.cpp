    bool search_help(TrieNode* root, string word){
        if(word.size()==0)
            return root->isTerminal;
        TrieNode* child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL) {
        child = root->children[index];
        } 
        else
            return false;
        return search_help(child,  word.substr(1));
    }

 bool search(string word) {
        return search_help(root,  word);
 }
