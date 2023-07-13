// reverse the elements in the input stack in the input stack itself using an extra stack

// Time complexity O(n^2) , space complexity O(n)
void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.empty())  // base case
        return;        

    // Small calculation includes popping up the first element of the input stack and storing it in another variable 
    // After the recursive call, the elements in the stack are reversed except the first element 
    // After that first element of the input array which was stored in the 'first' variable is pushed into the extra stack and after it, the whole input stack is copied into it 
    // Now the elements present in the extra stack is completely reverse of that of the input stack, therefore we just copied it into our old input 
  
    int first = input.top();
    input.pop();
    reverseStack(input,extra); 
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }

    input.push(first);
    while (!extra.empty()) {
      input.push(extra.top());
      extra.pop();
    }
}
