#include <bits/stdc++.h>
using namespace std;

int rec(vector<int>& arr, int index, int k){
    if(index == 0) return 0;
    int ans = INT_MAX;
    for(int j = 1; j <= k; j++){
        if(index >= j){
            int res = rec(arr,index-j,k) + abs(arr[index] - arr[index-j]);
            ans = min(ans,res);
        }
    }
    return ans;
}
// Time complexity: O(n*k), Space complexity: O(n*k)

int tab(int n, vector<int>& arr, int k){
    vector<int>dp(n,0);
    for(int i = 1; i < n; i++){
        int minSteps = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i-j < 0) break;
            minSteps = min(minSteps, abs(arr[i] - arr[i-j]) + dp[i-j]);
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }
    cout << tab(n,heights,k) << endl;
}
