Node *appendLastNToFirst(Node *head, int n){

	if(!head){
		return head;
	}   // edge cases 
	if(n<=0){
		return head;
	}

	int count = 0; // To find the length of the linked list
	Node* temp= head;
	while(temp!=NULL){
		if(temp!=NULL){
			count++;
			temp=temp->next ;
		}
	}  // count stores the length of the linked list
  
	int start = count - n;     // Calculate the position from the beginning where the last N nodes start
	temp=head;
	for( int i=0 ; i<start-1;i++){  // Traverse to the node just before the starting position
		temp=temp->next;
	}
	Node* newHead = temp->next ;
	temp->next =NULL ;

   // Traverse to the end of the new list and link it to the original head
	temp=newHead;
	while(temp->next!=NULL){ 
		temp=temp->next;
	}
	temp->next=head;
	return newHead;
}

