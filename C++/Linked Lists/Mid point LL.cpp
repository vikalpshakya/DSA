// ---Turtle approach----// 
//  Time complexity O(n) , space complexity O(1) 

Node *midPoint(Node *head)
{
    if(!head || head->next==NULL){
		return head;
	}
	Node* slow=head ;
	Node* fast = head->next;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow ; 
}
