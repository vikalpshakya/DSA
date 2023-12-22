#include <bits/stdc++.h> 

void helper(stack<int>& st, int x){
    if(st.empty()) {
        st.push(x);
        return ;
    }
    int top = st.top();
    st.pop();
    // recursive call 
    helper(st,x);
    st.push(top);
}


stack<int> pushAtBottom(stack<int>& myStack, int x) {
    helper(myStack,x);
    return myStack;
}
