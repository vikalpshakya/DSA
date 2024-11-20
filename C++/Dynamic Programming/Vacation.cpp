/*

problem link: https://atcoder.jp/contests/dp/tasks/dp_c

video link : https:https://www.youtube.com/live/luyErUWATsY?si=235YXGiZxluEbQ8G

*/

#include<bits/stdc++.h>
#define int long long
using namespace std; 

vector<vector<int>>cost;
int n; 

int dp[3][100100];

int rec(int level, int lastTook) {
    if(level == n) return 0;

    if(lastTook != -1 && dp[lastTook][level] != -1) return dp[lastTook][level];

    int ans = 0;


    for(int i = 0; i < 3; i++) {
        if(i != lastTook) {                                  // nice approach top check the last taken element 
            ans =  max(ans,cost[i][level] + rec(level+1,i));
        }
    }

    if(lastTook == -1) return ans;
    return dp[lastTook][level] = ans;

}


void solve() {
    cin >> n;
   
   cost.resize(3);

   for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
        int a; cin >> a;
        cost[j].pb(a);
    }
   }
    memset(dp,-1,sizeof(dp));

    // for(int i = 0; i < cost.size(); i++) {
    //     for(int j = 0; j < cost[i].size(); j++) {
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << rec(0,-1);

}

signed main(){
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
