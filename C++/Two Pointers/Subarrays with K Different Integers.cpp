// Timme complexity: O(n) , Space complexity: O(n) 
class Solution {
public:

    // this code is for to count number of subbarays <= k 

    // from this , if we can to count #subbarays == k , then we can simply find #sub(k)-#sub(k-1);

    int solve(vector<int>&vec, int k) {
        int n = vec.size();
        int head = -1, tail = 0, ans = 0;

        map<int,int>mp; int count = 0;

        while(tail < n) {
            while(head+1 < n && (count < k || mp[vec[head+1]] >= 1)) {
                head++;
                if(mp[vec[head]]==0){
                    count++;
                }
                mp[vec[head]]++;    
                
            }
            ans += (head-tail+1);

            if(head < tail) 
                head = tail++;
            else {
                mp[vec[tail]]--;
                if(mp[vec[tail]]==0) count--;
                tail++;;
            }
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& vec, int k) {

        return solve(vec,k)-solve(vec,k-1);

    }
};
