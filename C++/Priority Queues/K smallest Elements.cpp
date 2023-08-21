  /* Time complexity: O(N * log(K))
      Space complexity: O(K)
  
      where N is the size of the input array
      and K is the number of smallest elements that are to be found
*/

#include <bits/stdc++.h>
vector<int> kSmallest(int arr[], int n, int k) {
    vector<int>ans;
    priority_queue<int>pq;
    for ( int i = 0 ; i < k; i++) {
        pq.push(arr[i]);
    }
    int  j = k;
    while(j < n){
        if(arr[j] < pq.top()){
            pq.pop();
            pq.push(arr[j]);
        }
        j++;
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}




