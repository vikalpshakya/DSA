// Time O(n), space O(n) .

#include <bits/stdc++.h>
void calculateSpan(int prices[], int n, int spans[]) {
    vector <int> ans;
    stack<pair<int,int>> s ; 
    for( int i = 0 ; i < n ; i++){
        int days = 1 ;
        while ( !s.empty() && s.top().first < prices[i]){
            days+=s.top().second;
            s.pop();
        }
        s.push({prices[i] , days});
        ans.push_back(days);
    }
    for( int x=0;x<ans.size();x++){
        spans[x] = ans[x];
    }
  return span ; 
}
