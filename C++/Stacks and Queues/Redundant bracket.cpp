// Time complexity O(n) , space complexity O(n) 

#include <bits/stdc++.h>
bool checkRedundantBrackets(string expression) {
	int count = 0 ;
	stack <char>st;
	bool redundant = false ;
	int size = expression.size();
	for ( int i=0;i<size;i++){
		if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/'||expression[i]=='('){
			st.push(expression[i]);
		}
		else if(expression[i]==')'){
			if (st.top() == '(') redundant = true;
      while(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'){
				st.pop();
			}
			st.pop();
		}
			
		}
		return redundant;
}
