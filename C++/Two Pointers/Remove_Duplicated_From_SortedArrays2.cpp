
// Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

    int removeDuplicates(vector<int>& vec) {
        int i = 1, j = 1; 
        int n = vec.size();
        int cnt = 1;

        // i -> tail , j -> head 

        while(i < n) {
            if(vec[i] == vec[i-1]) {
                cnt++;
            }
            else cnt = 1;

            // if the count become more than 2 ,
            // we stop the j pointer thier only until we get another unique element

            if(cnt <= 2) {  
                vec[j] = vec[i];
                // cout << "swap at " << j << " " << i << endl;
                j++;
            }
            i++;

        }
        return j;
    }
