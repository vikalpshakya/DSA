#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb(i) push_back(i)
int n;  
int depth[200100];
vector<int>tree[200100];

void dfs(int node , int par, int dep) {
    depth[node] = dep;
    for(auto it: tree[node]) {
        if(it != par) {
            dfs(it,node ,dep+1);
        }
    }
}

void solve() {
   cin >> n;

    rep(i,n-1) {
        int u,v; cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    
    dfs(1,-1,0);

    int maxi = 1,maxD = 0;
    rep(i,n+1) {
        if(depth[i] > maxD) {
            maxi = i;
            maxD = depth[i];
        }
    }

    dfs(maxi,-1,0);
    maxD = 0;

    rep(i,n+1) {
        if(depth[i] > maxD) {
            maxi = i;
            maxD = depth[i];
        }
    }
    cout << depth[maxi];
    // cout << maxD << endl;
   
}

signed main(){
    solve();
}
