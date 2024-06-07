// Article link : https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/

class Solution {
public:
    
    // Time complexity : O(n) 
    // using moores voting algorithm

    int majorityElement(vector<int>& vec) {
        
        int curr = vec[0] , n = vec.size();
        int vote = 0;

        for(int i = 1; i < n; i++) {
            if(vec[i] == curr) vote++;
            else if(vote == 0) curr = vec[i];
            else vote--;
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(vec[i] == curr) count++;
        }

        return count > n/2 ? curr : -1; 

    }
};
