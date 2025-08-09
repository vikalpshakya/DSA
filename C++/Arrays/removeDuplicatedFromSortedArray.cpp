    
    // Two pointers

    // TC: O(n), SC: O(1)

    int removeDuplicates(vector<int>& vec) {
        int i = 0, j = 1;
        int n = vec.size();
        while(j < n) {
            if(vec[i] != vec[j]) {
                vec[i+1] = vec[j];
                i++;
            }
            j++;
        }
        return i+1;
    }