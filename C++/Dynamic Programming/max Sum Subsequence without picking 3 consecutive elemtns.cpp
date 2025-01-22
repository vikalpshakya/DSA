// https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14004?tab=statement

#include<bits/stdc++.h>
#define int long long
#define input(x) for(auto &a:x) cin >> a;
using namespace std;

void solve() {
   int n; cin >> n;
   vector<int> vec(n); input(vec);

   int dp[n] = {0};

    if(n >= 3) {
        dp[0] = vec[0];
        dp[1] = vec[0]+ vec[1];
        dp[2] = (vec[0]+ vec[1]+ vec[2]) - min({vec[0], vec[1],vec[2]});
    }

   for(int i = 3; i < n; i++) {
        int a = dp[i-1];
        int b = vec[i] + dp[i-2];
        int c = vec[i]+vec[i-1] + dp[i-3];

        dp[i] = max({a,b,c});
   }
   cout << dp[n-1] << endl;
}

signed main(){

    solve();

}
