// problem link: https://www.codechef.com/AUG14/problems/REVERSE

#include<bits/stdc++.h>
#define ll long long
#define int long long
#define SHAKYA ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ceil(a,b) ((a+b)-1)/b
#define vi vector<int>
#define ppb pop_back()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
#define sumAll(x) accumulate(x.begin(),x.end(),0ull)
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<' ';
#define rep(i,n) for(int i=0;i<n;i++)
#define endl "\n"
#define skip continue;
using namespace std; 

int n,m;

void solve() {
  cin >> n >> m;
  vector<pair<int,int>>adj[n+1];
  for(int i = 1; i <= m; i++) {
    int a,b; cin >> a >> b;
    if(a == b) continue;
    adj[a].pb({b,0});
    adj[b].pb({a,1});
  }


  deque<int>dq;

  vector<int> dist(n+1, mod); 

  dq.push_front(1);
  dist[1] = 0;

  while(!dq.empty()) {
    int front = dq.front();
    dq.pop_front();
    for(auto &it: adj[front])   {
      int node = it.first;
      int wt = it.second;
      if(dist[front] + wt < dist[node]) 
      {
        dist[node] = dist[front]+wt;
      if(wt==1) {
        dq.push_back(node);
      }
      else dq.push_front(node);
      }
    }
  }
  
  cout << (dist[n] == mod ? -1 : dist[n] );
}

signed main(){
    SHAKYA
    ll tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
