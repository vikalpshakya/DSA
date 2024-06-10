// problem Link  : https://leetcode.com/problems/single-number-ii/description/

// Time Complexity: O(n) 

/*
Approach : 
1. check the set bits of all number position wise( 0 -> 31 ) . Now since every number is repeating 3 times except 1 ,
  so number of set bit of all number at a particular position would either be divisible by 3 (numOne%3==0) , or not (k%3==1) 
2. In case of numOne%3 == 1 , we notice that at this positon, the bit of that unique number is set . 
3. hence we will do this for all bits and thereby keep adding the set bit into our answer 
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;

        for(int k = 0; k <= 31; k++) {
            int temp = 1 << k;
            int numOne = 0;
            for(auto num: nums) {
                if((num & temp) != 0) {
                    numOne++;
                }  
            }

            if(numOne%3) {
                ans += temp;
            }
        }

        return ans;
      
    }
};
