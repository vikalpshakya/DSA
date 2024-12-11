#include<bits/stdc++.h>
using namespace std; 
string a,b,c; 
int n1,n2,n3;
int dp[101][101][101];

// TC: O(n^3) 

int rec(int i, int j , int k) { 
    if(i == n1 || j == n2 || k == n3) return 0;
    
    if(dp[i][j][k] != -1) return dp[i][j][k];

    int ans = 0;
    if(a[i] == b[j] && b[j] == c[k] && c[k] == a[i]) 
        ans = 1 + rec(i+1,j+1,k+1);
    
    int ans1 = 0, ans2 = 0, ans3 = 0;
    ans1 = rec(i+1,j,k);
    ans2 = rec(i,j+1,k);
    ans3 = rec(i,j,k+1);

    return dp[i][j][k] = max({ans,ans1,ans2,ans3});

}

int tab() {

    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            for(int k = 1; k <= n3; k++) {
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1] && c[k-1] == a[i-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1]; 
                }
                else {
                    dp[i][j][k] = max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                }
            }   
        }
    }
    return dp[n1][n2][n3];
}

void solve() {
   cin >> a >> b >> c;
    n1 = a.size(),n2 = b.size(),n3 = c.size();

    // memset(dp,-1,sizeof(dp));
    // cout << rec(0,0,0) << endl;

    cout << tab() << endl;

}


signed main(){
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
