#include "bits/stdc++.h"
// time: O(n*n), space: O(1)
int findUnique_naive(int *arr, int n) {
  if ( n ==1){
    return arr[0];
  }
  
  for(int i = 0;i<n;i++){
     if(arr[i] == -1)
       continue;
    bool isDup = false;
    for ( int j =i+1 ; j < n ; j++){
      if (arr[i]==arr[j]){
          arr[j] = -1;
          isDup = true;
        break;
      }
      
    }
    if(isDup==false)
       return arr[i];
  }
  // return 9;
}


// time: O(n), space: O(n)
int findUnique_better_map(int *arr, int n) {
    unordered_map<int, int> mp;  // <int, pair<int,int>>
    
    for(int i = 0;i<n;i++) {
      mp[arr[i]] +=1;
    }

    for(auto i:mp) {  
        if(i.second == 1)
           return i.first;
    }
}

// time: O(n), space: 0(1)
int findUnique_better_xor(int *arr, int n) {
    int uniqueVal = 0;
    for(int i=0; i<n; i++) {
      uniqueVal ^= arr[i];
    }

    return uniqueVal;
}
int findUnique_better_xor_rec(int *arr, int n) {
      if(n == 1)
         return arr[0];
      return  arr[n-1] ^ findUnique_better_xor_rec(arr, n-1);

}



int findUnique(int *arr, int n) {
  return findUnique_better_xor_rec(arr, n);
}

