
#include <bits/stdc++.h> 
void itr(stack<int> &st1,int N){
   int count = 0;
   int mid = N/2;
   stack<int>st;
   while(!st1.empty()){
      if(count == mid) {
         st1.pop();
      }
      else {
         st.push(st1.top());
         st1.pop();
      }
      count++;
   }

   while(!st.empty()){
      st1.push(st.top());
      st.pop();
   }
}

void rec(stack<int>& st1, int size, int count){
   if(count == size/2){
      st1.pop();
      return;
   }
   int ans = st1.top();
   st1.pop();
   // Recursive Call
   rec(st1,size,count+1);
   st1.push(ans);

}

void deleteMiddle(stack<int>&st1, int N){
   // itr(st1,N);
   rec(st1,N,0);
}



