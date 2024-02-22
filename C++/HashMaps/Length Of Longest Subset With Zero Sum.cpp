/*
Time complexity: O(N)
Space complexity: O(N)
where N is the size of the input array
*/
#include <unordered_map>

int lengthOfLongestSubsetWithZeroSum(int * arr, int n) {
  unordered_map < int, int > freq;
  for (int i = 1; i < n; i++) {
    arr[i] += arr[i - 1];
  }
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      if (m < i + 1) {
        m = i + 1;
      }
    } else if (freq.count(arr[i]) > 0) {
      if (m < i - freq[arr[i]]) {
        m = i - freq[arr[i]];
      }
    } else {
      freq[arr[i]] = i;
    }
  }
  return m;
}
