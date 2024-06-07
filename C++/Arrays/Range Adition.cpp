// Problem Link : https://www.lintcode.com/problem/903/

// Time Complexity: O(n^2) 

  // Brute force : 
    vector<int> getModifiedArray(int n, vector<vector<int>> &q) {

        vector<int>vec(n,0);
        
        for(int i = 0; i < q.size(); i++) {
            for(int j = q[i][0] ; j <= q[i][1]; j++){
                vec[j] += (q[i][2]);
            }

        }
        return vec;
    }

// Optimal Approach: 
// Used prifix sum concept , Placed the q[2] in vec at the starting of the range and placed -ve q[2] in vec at ending range + 1 (except for q[1] == n-1) 


// Time complexity : O(n) + O(q)  , q = number of queries
    vector<int> getModifiedArray(int n, vector<vector<int>> &q) {

        vector<int>vec(n,0);
        
        for(int i = 0; i < q.size(); i++) {
            vec[q[i][0]]+=q[i][2];
            if(q[i][1] < n-1) 
                vec[q[i][1]+1] += (-q[i][2]);
        }

        for(int i = 1; i < n; i++) {
            vec[i] += vec[i-1];
        }
        return vec;
    }
