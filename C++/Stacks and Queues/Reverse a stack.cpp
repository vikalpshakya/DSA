// reverse the elements in the input stack in the input stack itself using an extra stack

// Time complexity O(n^2) , space complexity O(n)

void insertAtBottom(stack<int>&st, int f) {

    if(st.empty()){
        st.push(f);
        return;
    }
    int x = st.top();
    st.pop();
    
    insertAtBottom(st, f);
    st.push(x);
}

void reverseStack(stack<int> &st) {
    if(st.empty())  // base case
        return;        

    // Small calculation includes popping up the first element of the input stack and storing it in another variable 
    // After the recursive call, the elements in the stack are reversed except the first element 
    // After that first element of the input array which was stored in the 'first' variable is pushed into the extra stack and after it, the whole input stack is copied into it 
    // Now the elements present in the recursive stack is completely reverse of that of the input stack, therefore we just copied it into our old input 
  
    int first = st.top();
    st.pop();
    reverseStack(st); 
    
    insertAtBottom(st, first);
}

