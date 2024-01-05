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

public:
    int lengthOfLIS(vector<int>& nums) {
        return rec(nums,-1,0);
    }
};
