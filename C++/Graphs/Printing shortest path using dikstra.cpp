// problem link: https://codeforces.com/problemset/problem/20/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n + 1, LLONG_MAX), parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    dist[1] = 0;

    pq.push({0, 1});
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edW = it.second;

            if (dis + edW < dist[adjNode]) {
                dist[adjNode] = dis + edW;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if (dist[n] ==  LLONG_MAX)
        return {-1};

    vector<int> path;
    int node = n;

    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());
    return path;
}

signed main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e, vector<int>(3));
    for(int i = 0; i < e; i++) {
        int u, v, wt; 
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
    }
    vector<int> path = shortestPath(v, e, edges);
    if(path[0] == -1) 
        cout << -1;
    else {
        for(auto i: path) 
            cout << i << " ";
    }
}
