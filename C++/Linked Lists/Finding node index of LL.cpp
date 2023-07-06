//Time complexity = O(n) , space complexity = O(1)
int findNode(Node *head, int n){
  
    Node* temp = head;
    int count =0;
    
    while(temp!=NULL){
        if(temp->data==n){
            return count;
        }
        temp=temp->next;
        count++;
    }
    return -1;
}
