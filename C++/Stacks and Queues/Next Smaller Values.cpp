#include <bits/stdc++.h>
using namespace std;

// Same approach would be used to find next greater element.

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    stack<int> st;
    vector<int> ans(n + 1, 0);

    for(int i = n; i >= 1; i--) {
        if(st.empty()) {
            st.push(i);
            continue;
        }
        int num = arr[i];
        while(!st.empty() && arr[st.top()] > num) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }

    return 0;
}
