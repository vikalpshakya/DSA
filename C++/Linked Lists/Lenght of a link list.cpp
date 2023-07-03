// Recursive approach 
// time complexity O(n) space complexity O(m)
int length_rec(Node *head){
    if(head==NULL){
        return 0;
    }
    return 1 + length_rec(head->next);

}

//Iterative approach
// time complexity O(n) , space complexity O(1)
int length_iterative(Node *head)
{
    Node* temp = head;
    int length = 0 ;
    while(temp!=NULL){
        if(temp!=NULL){
            length+=1;
            temp = temp->next;

        }   
    }
    return length;
}


int length(Node *head) {
  return length_rec(head);
//   return length_iterative(head);
}
