#include<bits/stdc++.h>
// Time complexity O(n) , Space complexity O(N)

int pairSum(int *arr, int n) {
	unordered_map<int,int> map;
	int count = 0;
	for ( int i = 0; i < n; i++){
		int ans = -arr[i];
		if(map[ans]){       // we will find -arr[i] in the map , and increase the count with its current frequency of -arr[i]
			count+=map[ans];
		}
		++map[arr[i]];
	}	
return count ;
}
