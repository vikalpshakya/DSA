#include <iostream> 
using namespace std;
/* Making class and input &print function ---------------------------*/
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

Node* takeInput(){
        int data;
        cin>>data;
        Node* head = NULL;
        Node* tail = NULL;
        while(data!=-1){
            Node* newNode= new Node(data);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=tail->next;
                }      
            cin>>data;
        }
        return head;
    }   
    
    void print(Node* head){
        while( head!=NULL){
            cout<< head->data<<" ";
            head=head->next;
        }
    }  
/*-------------Function to insert a node in Link list----------*/

Node* insertNode(Node *head,int i,int data){
        Node *newNode = new Node(data);
        int count = 0;
        Node*temp = head;
        if (i==0){                // different case for inserting node at 0th position
            newNode->next = head;
            head=newNode;
            return head;
        }
        while(temp!=NULL && count<i-1){
            temp = temp->next;
            count++;
        }
        if(temp!=NULL){
        Node *a= temp->next;
        temp->next =newNode;
        newNode->next=a;
        }
}
/*-----------------------------------------------------------------*/
int main() {
    
    Node* head=takeInput();
    print(head);
    int i, data;
    cin >> i >> data;
    insertNode(head, i , data);
    cout<<endl;
    print(head);
}
