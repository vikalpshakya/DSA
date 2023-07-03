///time complexity O(n) ,space complexity O(1)

void printIthNode(Node *head, int i)
{
	int index=0;
	Node* temp=head;
	while(temp!=NULL){
		if(index==i){
			cout<<temp->data<<endl;
			break;
		}
		temp=temp->next;
		index++;
	}
}
