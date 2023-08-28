#include<bits/stdc++.h>
/*
    Time complexity: O(N)
    Space complexity: O(N)

    where N is the size of input array
*/
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int,int>freq;
    for (int i = 0; i < n; ++i) {
        ++freq[arr1[i]];
    }
    for (int i = 0; i < m; ++i) {
        if (freq.find(arr2[i]) != freq.end()) {
          cout << arr2[i] << "\n";
        }
        if (freq[arr2[i]] > 1) {
            --freq[arr2[i]];
        } else {
            freq.erase(arr2[i]);
        }
    }
}
