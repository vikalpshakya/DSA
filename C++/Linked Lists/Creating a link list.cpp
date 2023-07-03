#include <iostream>
using namespace std;

class Node{ //making a class of type node
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
        while(data!=-1){ // taking input until user gives -1 as input [-1 is not included in the link list]
            Node* newNode= new Node(data);
            if(head==NULL){
                head=newNode;
            }
            else{
                Node* temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newNode;
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
        
int main(){
    Node* head = takeInput();
    print(head);
}

