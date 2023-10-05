#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7; 

int mod(int n) {return n%MOD ;}

// --------APPROACH 1 [Recursive]--------//

// ------Time complexity: O(3^n), Space complexity: O(n) -----//

int staircase(int n) {
  if (n == 1 || n == 2)
    return n;

  if (n == 3)
    return 4;

  return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

// --------APPROACH 2 [DP + Memoisation]--------//

// ------Time complexity: O(n), Space complexity: O(n) -----//

int staircase_memoHelp(int n, vector<int>&dp){
  if(n == 1 || n == 2) return n;
  if(n == 3) return 4;
  if(dp[n] != -1) return dp[n];
  int a = staircase_memoHelp(n-1 ,dp );
  int b = staircase_memoHelp(n-2 ,dp );
  int c = staircase_memoHelp(n-3 ,dp );
  dp[n] = mod(mod( a)+ mod(mod(b) + mod(c))) ;
  return dp[n];
}

int staircase_memo(int n){
  vector<int>dp(n+1, -1);
  return staircase_memoHelp(n, dp);
}
// --------APPROACH 3 [DP + Tabulation]--------//

// ------Time complexity: O(n), Space complexity: O(n) -----//

int staircase_tab(int n ){
  vector<int>dp(n+1,0);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  int a ,b ,c ;
  for(int i = 4; i <= n; i++){
    if(dp[n] != 0) return dp[n];
     a = dp[i-1];
     b = dp[i-2];
     c = dp[i-3];
    dp[i] = mod(mod( a)+ mod(mod(b) + mod(c))) ;
  }
    return dp[n];
}

// --------------MAIN FUNCTION --------------//

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        cout << staircase_tab(n) << "\n" ;
    }
    return 0;
}
