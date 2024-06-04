// TC : O(NlogK)  k = size of the window 

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k; cin >> n >> k;
    vector<int>vec(n);
    for(auto &i : vec) cin >> i;
    
    multiset<int>ms;
    
    for(int i = 0; i < n; i++) {
        ms.insert(vec[i]);
        if(i >= 2) {
            cout << *ms.begin() << " ";
            ms.erase(ms.find(*ms.begin()));
        }
    }
    
}
