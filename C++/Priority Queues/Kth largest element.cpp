#include <bits/stdc++.h>
/*
    Time complexity: O(N * log(K))
    Space complexity: O(K)

    where K is the position (ordered by increasing value) of the element you need to find
*/
int kthLargest(int* arr, int n, int k) {
    priority_queue<int , vector<int>,greater<int> >pq;
    for( int i = 0 ; i < k; i++){
        pq.push(arr[i]);
    }
    int j = k;
    while( j < n){
        if(arr[j] > pq.top()){
            pq.pop();
            pq.push(arr[j]);
        }
        j++;
    }
    return pq.top();
}
