#include<bits/stdc++.h>
const int mod = 1e9 + 7;

// --------------APPROACH 1 [Recursive] -----------//

// ----Time complexity: O(2^n), Space complexity: O(n)-------//


int balancedBTs_rec(int h) {
    if(h == 0 || h == 1) return 1;
    int x = balancedBTs_rec(h - 1);
    int y = balancedBTs_rec(h - 2);
    int temp1 = (int) (( (long) (x) * x) % mod);
    int temp2 = (int) ((2* (long) (x)* y ) % mod);
    int ans = (temp1+temp2) % mod;
    return ans;

}
// --------------APPROACH 2 [DP + Memoisation] -----------//

// ----Time complexity: O(n), Space complexity: O(n)-------//

int solve_memHelp(int h , vector<int>&dp) {
    if(h == 0 || h == 1) return 1;
    if(dp[h] != -1) return dp[h];
    int x = solve_memHelp(h - 1,dp);
    int y = solve_memHelp(h - 2,dp);
    int temp1 = (int) (( (long) (x) * x) % mod);
    int temp2 = (int) ((2* (long) (x)* y ) % mod);
    int ans = (temp1+temp2) % mod;
    dp[h] = ans;
    return dp[h];

}
int solve_mem(int h ) {
    vector<int>dp (h+1 , -1);
    return solve_memHelp(h, dp);
}

// --------------APPROACH 3 [DP + Tabulation] -----------//

// ----Time complexity: O(n), Space complexity: O(n)-------//

int solve_tab(int h) {
    vector<int>dp(h+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for( int i = 2; i <= h; i++){
        int x = dp[i - 1];
        int y = dp[i - 2];
        int temp1 = (int) (( (long) (x) * x) % mod);
        int temp2 = (int) ((2* (long) (x)* y ) % mod);
        int ans = (temp1+temp2) % mod;
        dp[i] = ans;
    }
    return dp[h];
}

// -------------MAIN FUNTION  --------------//

int balancedBTs(int h){
    // return solve_mem(h);
    return solve_tab(h);
}


