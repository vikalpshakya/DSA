// time complexity O(n) , space O(1) ;

Node *evenAfterOdd(Node *head)
{
	if(!head){
		return head; 
	}
	Node*oddHead = NULL ;
	Node*evenHead = NULL ;
	Node*oddTail = NULL ;
	Node* evenTail = NULL ;
	Node*temp = head ; 
	while (temp!=NULL){
		if(temp->data % 2!= 0){
			if(oddHead==NULL){
				oddHead = temp ;
				oddTail = temp ; 
			}
			else{
				oddTail->next=temp;
				oddTail = temp;
			}
		}
		else{
			if(evenHead==NULL){
				evenHead = temp ;
				evenTail = temp ;
                }
			 else {
				 evenTail->next=temp;
                  evenTail = temp;
                    }
                }
				temp= temp->next;
		}
		if(oddHead==NULL){
			return evenHead ;
		}
	oddTail->next=evenHead ; 
	if(evenTail!=NULL){
		evenTail->next = NULL;
	}
	return oddHead ; 
	} 
