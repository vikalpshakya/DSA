#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(NLogN) ; Space complexity: O(1)

int main() {
    vector<int>ans = {4,5,3,12,9,22,45,7};
    sort(ans.begin(),ans.end());
    int i =0;
    while(i < ans.size()){
        swap(ans[i],ans[i+1]);
        i+=2;
    }
    for(int i =0; i<ans.size();i++){
        cout << ans[i]<<" ";
    }
}
