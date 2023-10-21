class Solution {

    // ---------APPROACH 1 [ RECURSIVE ]------- // 
    // -------Time complexity: O(2^(m*n)), Space complexity: O(max(m,n)) ------//

    int lcs(string a, string b) {
        // Base case
        if(a.size() == 0 || b.size() == 0) return 0;
        
        if(a[0] == b[0])  
            return 1+ lcs(a.substr(1), b.substr(1));
        else{
            int ans1 = lcs(a.substr(1), b);
            int ans2 = lcs(a, b.substr(1));
            return max(ans1,ans2);
        }
        
    }

    // --------APPROACH 2 [DP + Memoisation] --------// 
    // -------Time complexity: O(m*n), Space complexity: O(m*n) ------//


    int lcs_mem(string a, string b, vector<vector<int>>&dp) {
        int m = a.size();
        int n = b.size();
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int ans;
        if(a[0] == b[0]) 
            ans =  1+ lcs_mem(a.substr(1), b.substr(1),dp);
        else{
            int ans1 = lcs_mem(a.substr(1), b, dp);
            int ans2 = lcs_mem(a, b.substr(1), dp);
            ans = max(ans1,ans2);
        }
        return dp[m][n]= ans;  
        
    }
    int lcs_memoisation(string a, string b){
        int m = a.size();
        int n = b.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return lcs_mem(a,b,dp);
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcs_memoisation(text1,text2);
    }
};
