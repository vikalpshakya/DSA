int length(Node *head)
{
    int length=0;
	    while(head!=NULL){
		    length++;
			head=head->next;
						    }
	return length;
}
