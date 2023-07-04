//  time complexity O(n) , space complexity O(1) 
// 1 testcase getting failed

Node *deleteNode(Node *head, int pos)
{
	if(!head) 
	    return head;

	if(pos==0){
		head=head->next;
		return head;
	}
	else{
		Node* temp= head;
		int count = 0 ;  
		while(temp!=NULL && count < pos){
			if(count==pos-1){
				Node*a=temp->next;
				if(a==NULL){
					return head;
				}
				Node*b=a->next;
				temp->next=b;
				delete a;
			}
			temp=temp->next;
			count++;
	}
	
	return head;
	}
}
