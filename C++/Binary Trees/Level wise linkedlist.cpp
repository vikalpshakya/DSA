/*QUES.    Given a binary tree, write code to create a separate linked list for each level.
    You need to return the array which contains the head of each level linked list.
  
  Sample Input 1:                                              Sample Output 1:
 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1                                      5 
                                                                        6 10 
                                                                        2 3 
                                                                        9          
    Time complexity: O(N)
    Space complexity: O(H)                  */

#include <bits/stdc++.h> 
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
	vector<Node<int>*> output;
    if ( root == nullptr) return output ;
	queue<BinaryTreeNode<int>*> q ;
	q.push(root);
	int currentlevelRem = 1 , nextLevelCount = 0;
	Node<int>* currentHead = NULL ;
	Node<int>*currentTail = NULL ;
	while ( !q.empty()) {
		BinaryTreeNode<int>*first = q.front();
		q.pop();
		Node<int>* newHead = new Node<int>(first->data);
		if( currentHead == NULL){
			currentHead = newHead;
			currentTail = newHead;
		}
		else {
			currentTail->next = newHead;
			currentTail = newHead ;}
	
		if(first->left != NULL) {
			q.push(first->left);
			nextLevelCount++;
		}
		if(first->right != NULL) {
			q.push(first->right);
			nextLevelCount++;
		}
		currentlevelRem--;
		if(currentlevelRem == 0){
			output.push_back(currentHead);
			currentHead = NULL;
			currentTail = NULL;
			currentlevelRem = nextLevelCount ;
			nextLevelCount = 0 ;
		}
		}		
		return output;
}

/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/


                    
