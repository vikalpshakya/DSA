#include <bits/stdc++.h>

// Time complexity O(N) , space complexity O(N)

int highestFrequency(int arr[], int n) {
    int count = 0;
    unordered_map<int,int> map;
    for(int i = 0; i < n; i++){
        ++map[arr[i]];
        count = max(count , map[arr[i]]);
    }
    int mostFrequent;
    for( int i = 0; i < n; i++ ){
        if(map[arr[i]] == count ){
            mostFrequent = arr[i];
            break;
        }
    }
    return mostFrequent;
}
