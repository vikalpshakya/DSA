// Time complexity = O(n) , space O(n)

int findNodeRec(Node *head, int n)
{
	if(!head){
		return -1;
	}
	else if(head->data == n){
		return 0;
	}
	int index = findNodeRec(head->next, n) ; 
	if(index!=-1){
		return 1+ index;
	}
	else
	return -1 ;
}
