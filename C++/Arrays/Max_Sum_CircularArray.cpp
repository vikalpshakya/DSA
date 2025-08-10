


//  [ - - - . . . . - - - ] where - is the part of max sum subarray
//  so . . . would be the min sum subbarray of the array , 
//  therefore the ans would totalSum - minSumSubarray

    int maxSubarraySumCircular(vector<int>& vec) {
        int maxSum = vec[0] , currMnSum = 0;
        int minSum = vec[0] , currMxSum = 0;
        int totalSum = 0    , n = vec.size();

        for(int i = 0; i < n; i++) {
            currMxSum += vec[i];
            currMnSum += vec[i];

            maxSum = max(maxSum,currMxSum);
            minSum = min(minSum,currMnSum);

            if(currMxSum < 0) currMxSum = 0;
            if(currMnSum > 0) currMnSum = 0;
            
            totalSum += vec[i];
        }

        // cout << maxSum << " " << minSum << endl;

        if(maxSum < 0) return maxSum; // if all elements are -ve , then ans = max element

        return max(maxSum , totalSum - minSum);

    }



