// Time complexity O(n(log k));
// Space complexity O(k)

#include <bits/stdc++.h>
vector<int> kLargest(int input[], int n, int k){
   priority_queue<int , vector<int> , greater<int> >pq;
   for ( int i = 0 ; i < k; i++){
       pq.push(input[i]);
   }
   int j = k;
   while( j < n) {
       if(input[j] > pq.top()){
           pq.pop();
           pq.push(input[j]);
       }
       j++;
   }
   vector<int>ans;
   while(!pq.empty()){
       ans.push_back(pq.top());
       pq.pop();
   }
   return ans;
}

