// Time complexity O(n) , Space complexity O(n/k)

Node *kReverse(Node *head, int k){
	if(!head||head->next==NULL ||k==0) // base case 
		return head;    
		
	Node*next =NULL;
	int count = 0;
	Node* prev=NULL;
	Node* current = head;
	while(current!=NULL&&count<k){
		next = current->next;
		current->next = prev;
		prev = current;
		current=next;
		count++;
				}
		if (next !=NULL) {
			head->next = kReverse(next,k);
		}
		return prev;
}
