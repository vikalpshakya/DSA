#include<bits/stdc++.h>
// -----------------------Approach 1 --------------------------//
// Time complexity O(nLog N)
// Space complexity O(N) 

bool isMaxHeap_approach1(int arr[], int n) {
    priority_queue<int>pq;
    for ( int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    int i = 0;  
    while(!pq.empty()) {
        if ( i >= n ||arr[i++] != pq.top()) {
            return false;
        }
        pq.pop();
    }
    return true;
} 
// ---------------------Approach 2--------------------------//
// Time complexity O(n) 
// Space complexity O(1) 

bool isMaxHeap_approach2(int arr[], int n) {
    if(n == 1) return true;
    int leftChildIndex , rightChildIndex;

    for (int i = 0; i < n; i++) {
        leftChildIndex = 2 * i + 1;
        rightChildIndex = 2 * i  + 2;
        if(leftChildIndex < n && arr[i] < arr[leftChildIndex] )
            return false;
        if( rightChildIndex < n && arr[i] < arr[rightChildIndex ] )
             return false;
    }
    return true;
}

bool isMaxHeap(int arr[], int n) {
    return isMaxHeap_approach2(arr,  n);
    // return isMaxHeap_approach1(arr,  n);
}








