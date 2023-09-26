class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childcount;

    TrieNode(char ch){
        data = ch;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childcount = 0;
    }
};

class Trie{
    public:
    TrieNode *root;

    Trie(char ch){
        root = new TrieNode(ch);
    }

    void insertWord(string word){
        insertUtil(root , word);
    }

    void insertUtil(TrieNode *root , string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childcount++;
        }

        insertUtil(child , word.substr(1));
    }

    void lcp(string str , string &ans){
        for(int i = 0 ; i < str.length() ; i++){
            char ch = str[i];

            if(root->childcount == 1){
                ans += ch;
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal == true)
                break;
        }
    }
};
// Time complexity: O(m*n), Space complexity: O(m*n) [m = length of a string, n = number of strings]

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t = new Trie('\0');

        for(int i = 0 ; i < strs.size() ; i++){
            if(strs[i] == "")
                return "";
            else
                t->insertWord(strs[i]);
        }

        string first = strs[0];
        string ans = "";

        t->lcp(first , ans);
        return ans;
    }
};
