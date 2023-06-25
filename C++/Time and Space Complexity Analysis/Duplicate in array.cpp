#include "bits/stdc++.h"

// time O(nlogn+n) , space O(1)
int findDuplicate_sort(int *arr, int n) {
  sort(arr,arr+n);
  for ( int  i =0 ; i<n;i++){
      if ( arr[i]==arr[i+1]){
          return arr[i];
      }
  }
}


//time : 0(n), space: O(1)
int findDuplicate_sum(int *arr, int n) {
    int sumOfArray = accumulate(arr, arr+n, 0);
    int sumOfNum = (n-2)*(n-1)/2;
    // ---- usd accumulate instead of below
    // for ( int i = 0 ; i < n ; i++){
    //     sum+=arr[i];
    // }
    // for (int i = 0; i < n-1; i++) {
    //   sumOfNum+= i ;
    //     }
    
    return sumOfArray-sumOfNum;
}


int findDuplicate(int *arr, int n) {
    return findDuplicate_sum(arr, n);
}









