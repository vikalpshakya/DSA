// For a given expression in the form of a string, 
// find the minimum number of brackets that can be reversed in order to make the expression balanced. 
// The expression will only contain curly bracket

/*
    Time complexity: O(N)
    Space complexity: O(N)

    where N is the number of brackets
*/


#include<bits/stdc++.h>

int countBracketReversals(string input) {
	int len = input.size();
	if(len%2 != 0) 
	  return -1;

	stack<char> st;

	for (int i = 0; i < len; i++) {
		if(input[i] == '{')
	   	  st.push(input[i]);
        else {
             if (!st.empty() && st.top() ==  '{')
			    st.pop();
			else
			   st.push(input[i]);
        }
    }

	// counting steps
	int count = 0;
	while(!st.empty()) {
		char firstTop = st.top();
		st.pop();

		char secondTop = st.top();
		st.pop();

		if(secondTop == firstTop)
		  count += 1;
        else
		  count += 2;
	}
    return count;

}
