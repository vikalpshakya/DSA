 int findNumberOfLIS(vector<int>& vec) {
        int n = vec.size();
        int maxi = 1;
        vector<int>dp(n,1);   // -> length of LIS ending at i
        vector<int>count(n,1);// -> count of no. of curr LIS ending at i

        for(int i = 1; i < n; i++) {
            for(int prev = 0; prev <= i; prev++) {
                if(vec[i] > vec[prev] && dp[prev]+1 > dp[i]) {
                    dp[i] = max(dp[i],dp[prev]+1); 
                    count[i] = count[prev];
                }
                else if(vec[i] > vec[prev] && dp[i] == dp[prev]+1) {
                    count[i] += count[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi) ans += count[i];
        }

        return ans;

  }
