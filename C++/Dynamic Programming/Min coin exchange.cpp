int dp[10001];
class Solution {
private:
    int rec(vector<int>& vec, int target) {
        if(target == 0) return 0;
        if(target < 0) return INT_MAX;
        int mini = INT_MAX;
        for(int i = 0; i < vec.size(); i++){
            int ans = rec(vec,target-vec[i]);
            if(ans != INT_MAX)
                mini = min(mini, ans + 1);
        }
        return mini;
    }

    int mem(vector<int>& vec, int target){
        if(target == 0) return 0;
        if(target < 0) return INT_MAX;
        if(dp[target] != -1) return dp[target];
        int mini = INT_MAX;
        for(int i = 0; i < vec.size(); i++){
            int ans = mem(vec,target-vec[i]);
            if(ans != INT_MAX)
                mini = min(mini, ans + 1);
        }
        return dp[target] = mini;
    }

    int tab(vector<int>& vec, int target){
        vector<int> dp(target+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= target; i++){
            for(int j = 0; j < vec.size(); j++){
                if((i - vec[j] >= 0) && dp[i - vec[j]] != INT_MAX){
                    int ans = dp[i - vec[j]];
                    dp[i] = min(ans + 1, dp[i]);
                }
            }
        }   
        return dp[target];   

    }

public:
    int coinChange(vector<int>& coins, int amount) {
    //   memset(dp,-1,sizeof(dp));
      int ans = tab(coins,amount);  
      return ans == INT_MAX ? -1 : ans;
    }
};
