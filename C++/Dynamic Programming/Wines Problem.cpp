#include <bits/stdc++.h>
using namespace std;
// problem link: https://medium.com/trick-the-interviwer/wine-selling-problem-4f6886d8ed6d

int dp[1001][1001];

// Time complexity: O(n^2), Space Complexity: O(n^2) 

int maxCost(vector<int>&vec, int s, int e, int n) {
    id(s > e) return 0;
    if(s == e) return vec[s]*n;
    if(dp[s][e] != -1) return dp[s][e];
    int ans = n*vec[s] + maxCost(vec,s+1,e,n+1);
    int ans2 = n*vec[e] + maxCost(vec,s,e-1,n+1);
    return dp[s][e] = max(ans,ans2);

    
}


int main() {
    int n; cin >> n;
    vector<int>vec(n);
    
    for(auto &i : vec) cin >> i;
    
    memset(dp,-1,sizeof(dp));
    
    cout << maxCost(vec,0,n-1, 1);
    
    
    
} 
