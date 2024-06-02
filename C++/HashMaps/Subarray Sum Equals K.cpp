/*
Time complexity: O(nlogn)
Space complexity: O(n) 
*/
// QP : https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        map<int,int> mp;
        vector<int>pre(nums.size(),0);
        pre[0] = nums[0];

        for(int i = 1; i < nums.size(); i++) pre[i] = pre[i-1] + nums[i];

        for(int i = 0; i < nums.size(); i++) {

            if(pre[i] == k ) count++;
            count += mp[pre[i]-k];

            mp[pre[i]]++;
        }
        return count;


    }
};
