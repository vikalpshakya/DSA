
// problem link: https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    bool check(int mid, vector<int>vec, int k) {
        int z = 0, n= vec.size();

        for(int i = 0; i < n; i ++) {
            if(vec[i] == 1) {
                i >= mid ? z-=vec[i-mid]==0: z ;
            }
            else {
                z++;
                i >= mid ? z-=vec[i-mid]==0: z ;
            }
            if(i >= mid-1 && z <= k) return true;
            
        }
        return false;
    }

    int longestOnes(vector<int>& nums, int k) {
        
        int s = 0, e = nums.size();
        int ans = k;

        while(s <= e) {
            int mid = s +(e-s)/2;
            if(check(mid,nums,k)) {
                ans = mid;
                s = mid+1;
            }
            else 
                e = mid-1;

        }

        return ans;

    }
};
