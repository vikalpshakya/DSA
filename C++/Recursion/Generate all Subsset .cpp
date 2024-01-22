
// Time Complexity: O(2^n) , Space : O(n) 

class Solution {
  private:
    vector<vector<int>>allSubset;

    void generateSubset(vector<int>&nums,vector<int>&temp,int i) {

        if( i == nums.size()) {
            allSubset.push_back(temp);
            return ;
        }
        // take
        temp.push_back(nums[i]);
        generateSubset(nums,temp,i+1);
        
        temp.pop_back(); // delete last element while backtracking

        // not Take
        generateSubset(nums,temp,i+1);

    }

  public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        generateSubset(nums,temp,0);
        return allSubset;
    }
};
