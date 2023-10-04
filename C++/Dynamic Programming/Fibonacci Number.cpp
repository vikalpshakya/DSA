#include<bits/stdc++.h>
using namespace std;
//------ Time complexity: O(n), Space complexity: O(n) -------//
  int fib_Help(int n , int *dp){
      if(n <= 1) return n;
      if(dp[n] != -1) return dp[n];
      int a = fib_Help(n-1, dp);
      int b = fib_Help(n-2, dp);
      dp[n] = a+b;
      return dp[n];
  }
  int fib(int n){
      int *dp = new int[n+1];
      for(int i = 0; i <= n; i++){
          dp[i] = -1;
      }
      return fib_Help(n,dp);
  }
int main(){
  int n; cin >> n;
cout << fib(n) << "\n";
}
