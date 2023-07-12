class Stack {   // Defining the data members
    Node*head;
    int size;

   public:
    Stack() {  // Constructor
        head = NULL;
        size = 0;
        
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {            // Implementing the getSize() function
        return size;  
    }

    bool isEmpty() {           // Implementing the isEmpty() function
        return size==0;   
    }

    void push(int element) {   // Implementing the push() function
        Node* newnode = new Node(element);
        newnode->next = head;
        head= newnode;
        size++ ; 
        }

    int pop() {                // Implementing the pop() function
        if(isEmpty()){
            return -1;
        }
        int ans = head->data;
        Node*temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

      int top() {               // Implementing the top() function
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};
