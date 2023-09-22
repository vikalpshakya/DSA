#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
void removeloop(Node* &head, Node* &slow);
void insertion(Node* &head,int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void create(Node* &head, int p){
    Node* temp1 = head;
    Node* temp2 = head;
    if(p<0){
        cout<<"invalid"<<endl;return;
    }
    for(int i=0;i<p;i++){
        temp1=temp1->next;
        if(temp1 == NULL){
            cout<<"INDEX OUT OF RANGE"<<endl;
            return;
        }
    }
    while(temp2->next != NULL){
        temp2= temp2->next;
    }
    temp2->next = temp1;
}

void detectloop(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && slow != NULL){
        slow = slow->next;
        if(fast->next != NULL){
            fast = fast->next->next;
        }
        if(slow == fast){
            cout<<"LOOP DETECTED"<<endl;
            removeloop(head,slow);
            return;
        }
    }
}

void removeloop(Node* &head, Node* &slow){
    Node* temp = head;
    while(temp != slow){
        temp = temp->next;
        slow = slow->next;
    }
    cout<<slow->data<<endl;
    while(temp->next != slow){
        temp=temp->next;
    }
    temp->next = NULL;
    cout<<"LOOP REMOVED"<<endl;
    return;
}

void display(Node* head){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    
    insertion(head,1);
    insertion(head,2);
    insertion(head,3);
    insertion(head,4);
    insertion(head,5);
    insertion(head,6);
    insertion(head,7);
    insertion(head,8);
    

    create(head,4);
    
    detectloop(head);
    
    display(head);
}
