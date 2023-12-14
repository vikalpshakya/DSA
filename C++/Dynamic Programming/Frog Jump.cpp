// problem link:  https://www.codingninjas.com/studio/problem-details/frog-jump_3621012


// Time complexity: O(n), Space complexity: O(n)

int tab(int n, vector<int>& heights){
    vector<int>dp(n,0);
    int right = INT_MAX, left;
    for(int i = 1; i < n; i++){
        left = dp[i-1] + abs(heights[i] - heights[i-1]);
        if(i > 1)
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        int ans = min(right,left);
        dp[i] = ans;
    }
    return dp[n-1];

}
// Time complexity: O(n), Space complexioty: O(1)

int SO(int n, vector<int>& heights){
    int prev1 = 0, prev2;
    int curr = INT_MAX , ans = INT_MAX;
    for(int i = 1; i < n; i++){
        curr = prev1 + abs(heights[i] - heights[i-1]);
        if(i > 1)
            ans = prev2 + abs(heights[i] - heights[i-2]);
        prev2 = prev1;
        prev1 = min(curr,ans);
    }
    return prev1;
}

int frogJump(int n, vector<int> &heights){
    return SO(n,heights);
}
