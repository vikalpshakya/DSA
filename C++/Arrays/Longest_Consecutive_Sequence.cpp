
// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/description/

// Time complexity: O(n) , Space complexity: O(n)

    int longestConsecutive(vector<int>& vec) {
        int count = 0;
        int n = vec.size();

        unordered_set<int>st;

        for(int i = 0; i < n; i++) {
            st.insert(vec[i]);
        }   

        // int itr = 0; // to count the number of iterations for TC check

        for(auto num : st) {// it's better to iterate in the set , to avoid duplicates
            int toFind = num;
            if(st.find(toFind-1) != st.end()) continue;

            int currLen = 1;
            while(st.find(toFind+1) != st.end()) {
                currLen++;
                toFind++;
                // itr++;
            }
            count = max(count,currLen);
        }
        // cout << itr << endl;
        return count;   
    }


    // ----------------------------------------------------------------------------------------- // 


    // Time complexity: O(n) , Space complexity: O(2*n)

    int longestConsecutive(vector<int>& vec) {
        int count = 0;
        int n = vec.size();

        unordered_set<int>st,vis;

        for(int i = 0; i < n; i++) {
            st.insert(vec[i]);
        }   

        // int itr = 0; // to count the number of iterations for TC check

        for(int i = 0; i < n; i++) {
            int toFind = vec[i];
            int currLen = 1;


            // we always have to start from the begining of the sequence
            if(st.find(toFind-1) == st.end()) {

                if(vis.find(toFind) != vis.end()) continue; // already visited
                vis.insert(toFind);

                while(st.find(toFind+1) != st.end()) {
                    currLen++;
                    toFind++;
                    // itr++;
                }
            }
            count = max(count,currLen);
        }
        // cout << itr << endl;
        return count;   
    }
