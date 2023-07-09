// Time complexity O(n), space complexity O(1)


Node *reverseLinkedList(Node *head) {
	Node*prev= NULL;
	Node* current = head ; 
	while ( current!=NULL){
		Node* next = current->next;
		current->next= prev;
		prev = current ;
		current = next ;
	}
	return prev ; 
}
