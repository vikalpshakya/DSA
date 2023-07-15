// Time O(n) space 0(n)

void deleteAlternateNodes(Node *head) {
    if(head==nullptr||head->next==nullptr ) // base case 
       return;

      Node *temp = head->next;
      head->next = temp->next; // small calculation : attaching head to 3rd element 

      deleteAlternateNodes(head->next);
}
