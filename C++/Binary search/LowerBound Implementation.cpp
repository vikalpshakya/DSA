
// Time complexity: O(logN) 

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>arr, int k) {
    
    int s = 0, e = arr.size()-1;
    int ans = -1;
    while(s <= e) {
        int mid = s + (e-s)/2;
        if(arr[mid] >= k) {
            ans = mid;
            e = mid-1;
        }
        else
            s = mid+1;
    }
    return ans;
}


int main() {
    int n, k; cin >> n >> k;
    vector<int>vec(n); 
    for(auto&it:vec) cin >> it;
    cout << lowerBound(vec,k) << endl;
}
