// Ques link: https://leetcode.com/problems/search-in-rotated-sorted-array

// sol video link: https://www.youtube.com/watch?v=5qGrJbHhqFs

class Solution {
public:
// Time complexity: O(logn)  

    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;

        while(low <= high) {
            int mid = low+(high-low)/2;
            if(arr[mid] == target ) return mid;
            if(arr[low] <= arr[mid]) {
                (arr[low] <= target && target <= arr[mid]) ? high = mid-1 : low = mid+1;
            }
            else {
                (arr[mid] <= target && target <= arr[high]) ? low = mid+1 : high = mid-1;

            }

        }

        return -1;
    }
};
