// Time complexity = O(n) , space complexity O(n) 

/* ----------Recursive approach------------- */

void printReverse(Node *head)
{
	if(!head){
		return ;
	}
	if(head->next==NULL){
		cout<<head->data<<" ";
		return;
	}
	printReverse(head->next);
	cout<<head->data<<" ";
}
