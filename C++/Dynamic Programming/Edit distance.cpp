#include<bits/stdc++.h>

// --------- APPROACH 1 [DP+ Memoisation]  ----------- //

// ----------Time Complexity: O(n*m), Space Complexity: O(n*m) ----------- // 

int solve_mem(string a, string b, vector<vector<int>>&dp) {
    int n = a.size();
    int m = b.size();
    if (n == 0) return m;
    if (m == 0) return n;
    if(dp[n][m] != -1) return dp[n][m];
    int ans;
    if(a[0] == b[0])
        ans = solve_mem(a.substr(1), b.substr(1),dp);
    else{
        int step1 = solve_mem(a.substr(1), b,dp); // delete
        int step2 = solve_mem(a, b.substr(1),dp); // insert
        int step3 =solve_mem(a.substr(1), b.substr(1),dp); // replace
        ans = 1 + min({step1, step2, step3});
    }
    return dp[n][m] = ans;

}

int solve_memoisation(string a , string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1, -1));
    return solve_mem(a, b, dp);
}
