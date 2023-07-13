// time complexiy O(n) , space O(n) 

void reverseQueue(queue<int> &input) {
	if(input.size()==0) return  // base case
    
	int first = input.front();
	input.pop(); // small calculation 
  
	reverseQueue(input);
	input.push(first);
}
