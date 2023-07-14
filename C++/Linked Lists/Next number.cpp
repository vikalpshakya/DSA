// Question. - Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
// Sample Input 1 :   |   Sample Output 1 :
//     9 9 9 9        |        1 0 0 0 0


// Time complexity O(n) , space complexity O(n) [ bcz recursive apporach is used to find the reverse of LL]
Node* revLL(Node*head){
    if(!head || head->next == nullptr) return head;
    Node*first = head ;
    Node* newNode = revLL(head->next );
    head->next->next=head;
    head->next=NULL;
    return newNode;  
}

Node* NextLargeNumber(Node *head) {

    Node* newHead = revLL(head);
    Node* temp  = newHead ;
    Node* prev=nullptr;
    bool carry=true; // if all the numbers of linked list is 9 , then we have to add extra node at the start 
    while(temp!=NULL){
        if(carry){
            if (temp->data < 9) {
                temp->data += 1;
                carry = false;
            } else {
                temp->data = 0;
            }
        }
        prev=temp;
        temp=temp->next;
    }
    if(carry)
    {
        Node* newNode=new Node(1);
        prev->next=newNode;
    }
    return revLL(newHead);
}

// If there is a carry (initially set to true), it checks if the current node's data is less than 9.
// If so, it increments the data by 1 and sets carry to false. If the data is 9, it sets the data to 0.
// After the iteration, if there is still a carry, it means that a new most significant digit needs to be added.
// It creates a new node with the value 1 and sets it as the next node of the previous node (the last node of the original reversed linked list).





