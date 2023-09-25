#include <string>
#include <vector>
/*
Sample Input 1 :     4               (size of string vector)
                     abc def ghi cba (input strings)
                     de              (to find)
Sample Output 1 :   true            */
  
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
// ---------------------------------------------------------------
    bool search(TrieNode*root , string word){
        if(word.size() == 0) {
            return true;
        }
        TrieNode* child;
        int index = word[0] - 'a';
        if(root-> children[index] != NULL){
            child = root->children[index];
        }
        else return false;
        return search(child, word.substr(1));
    }

    bool search(string word){
        return search(root,  word);
    }


    bool patternMatching(vector<string> vect, string pattern) {
        for(int i = 0; i < vect.size(); i++){
            string word = vect[i]; 
            for(int j = 0; j < word.size(); j++){
                insertWord(word.substr(j));    // inserted all prefixes of the given strings in the trie
            }
        }
        return search(pattern);
    }
// -------------------------------------------------------------
};



