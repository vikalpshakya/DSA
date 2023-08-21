//  We are given with a K sorted array (k sorted array is an array where each element is at most k distances away from its target position in the sorted array. ) 
// We need to sort it completely in descending order

// Time complexity : O(n+k(log k)) , Since the value of k is very small 
// So we can consider the TIME COMPLEXITY to be O(N) , where n is the size of input array 

// Space complexity : O(k)

#include <bits/stdc++.h>
using namespace std;

void kSortedArray( int input[], int n, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < k ; i++) {
        pq.push(input[i]);
    }
    int j = 0;
    for(int i = k; i < n; i++) {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.empty()) {
        input[j++] = pq.top();
        pq.pop();
    }
}


int main() {
    int n = 5;
    int input[n] = {10,12,6,7,9};
    int k = 3;
    kSortedArray(input , n , k);
    for(int i = 0; i < n ;i++) {
        cout << input[i]<<" ";
    }
}
