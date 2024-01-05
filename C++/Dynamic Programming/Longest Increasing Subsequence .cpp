
class Solution {
private:

    // Time complexity: O(n^2), Space complexity: O(n) [ recursive stack space only ]

    int rec( vector<int>& nums, int prevInd, int currInd) {

        if(currInd == nums.size()) return 0;
        int take = 0, notTake = 0;
        
        if(prevInd == -1 || nums[prevInd] < nums[currInd]) {
            take = 1 + rec(nums,currInd,currInd+1);
        }
        notTake = rec(nums,prevInd,currInd+1);
        return max(notTake,take);

    }

// Time complexity: O(n*n), Space complexity: O(n*n)

int memo(vector<int>& nums, vector<vector<int>>& dp, int prevInd, int currInd) {

    if (currInd == nums.size()) return 0;

    if (prevInd != -1 && dp[prevInd][currInd] != -1) return dp[prevInd][currInd];

    int take = 0, notTake = 0;

    if (prevInd == -1 || nums[prevInd] < nums[currInd]) {
        take = 1 + memo(nums, dp, currInd, currInd + 1);
    }
    notTake = memo(nums, dp, prevInd, currInd + 1);
    
    if(prevInd!=-1)
        return dp[prevInd][currInd] = max(notTake, take);
    
    return max(take,notTake);
}


public:
    int lengthOfLIS(vector<int>& nums) {
        // return rec(nums,-1,0);
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return memo(nums,dp,-1,0);
    }
};
