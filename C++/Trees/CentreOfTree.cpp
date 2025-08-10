#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> dep;
vector<int> parent;
int d;

void dfs(int node, int par, int dist)
{
    parent[node] = par;
    dep[node] = dist;
    for (auto v : g[node])
    {
        if (v != par){
            dfs(v, node, dist + 1);
        }
    }
}

int main(){
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());
    parent.assign(n + 1, 0);
    dep.assign(n + 1, 0);

    int u, v;

    for (int i = 0; i < n - 1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    int mx = 1;
    for (int i = 2; i <= n; i++){
        if (dep[i] > dep[mx])
            mx = i;
    }

    dfs(mx, 0, 0);

    for (int i = 1; i <= n; i++){
        if (dep[i] > dep[mx])
            mx = i;
    }

    d = dep[mx];

    // cout<< d << " -- \n ";

    for (int i = 0; i < (d/2); i++){
        // cout << mx << " ";
        mx = parent[mx];
    }
        cout << mx << endl;
    
}