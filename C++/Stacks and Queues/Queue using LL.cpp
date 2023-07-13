//Everything is being done in order 0(n) time complexity 

/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/

class Queue {	// Define the data members
	Node*head;
	Node*tail;
	int size ;

   public:
    Queue() {	// Implement the Constructor
		head = NULL;
		tail=NULL;
		size=0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {		// Implement the getSize() function
		return size;		
	}

    bool isEmpty() {	// Implement the isEmpty() function
		if(size==0) return true;
		else return false;
		
	}

    void enqueue(int data) {	// Implement the enqueue() function
		Node* newNode = new Node(data);
		if( head==NULL){
			head=newNode;
			tail=newNode;
		}
		else{
			tail->next =newNode;
			tail=tail->next;
		}
		size++ ;
	}

    int dequeue() {		// Implement the dequeue() function
		if(head==NULL)
			return -1;
		int ans = head->data;
		head = head->next;
		size--;
		return ans;
	 }

    int front() {        // Implement the front() function
		return head->data;
    }
};
