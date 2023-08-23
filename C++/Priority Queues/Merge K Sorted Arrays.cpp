#include<bits/stdc++.h>

// ------------Naive approach --------------// 

// Time complexity O(n*k(Log n*k) )
// Space complexity O(n*k)

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    vector<int>ans;
   for (int i = 0; i < input.size(); ++i) {
     for (int j = 0; j < input[i]->size(); ++j) {
       ans.push_back(( *input[i])[j] );
     }
   }
   sort(ans.begin(), ans.end());
   return ans;
}
