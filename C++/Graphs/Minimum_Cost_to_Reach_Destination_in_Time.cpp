#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;

int maxT , n , e;
vector<int>fees;

int solve(vector<pair<int,int>>adj[]) {
    vector<int>time(n,1e9);
    time[0] = 0;

    priority_queue<pair<int,pair<int,int>>>pq;  // {fees , {time , node}}
    pq.push({-fees[0] , {0,0}});

    while(!pq.empty()) {
        auto [fee, disNode] = pq.top();
        int dist = disNode.f;
        int node = disNode.s;
        pq.pop();

        if(dist > maxT) continue;
        if(node == n-1) return -fee;

        for(auto it: adj[node]) {
            int v = it.f , w = it.s;
            if(time[v] < dist + w) continue;
            time[v] = dist + w;
            pq.push({-( -fee + fees[v] ) , {time[v] , v}});
        }
    }

    return -1;
}

int main() {
    cin >> maxT >> n >> e;
    vector<pair<int,int>>adj[n+1];

    for(int i = 0; i < e; i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    fees.assign(n,0);
    for(int i = 0; i < n; i++) cin >> fees[i];

    cout << solve(adj) << endl;
}
