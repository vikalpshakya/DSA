#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(V + E)
// Space complexity: O(V^2)


void bfs(vector<int>adj[],vector<bool>&visited,int n ,vector<int>&ans,int sv,int ev){
    queue<int>q;
    //vector<int>parent(n+1); // mapping parent to node values
    unordered_map<int,int>parent;
    parent[sv] = -1;
    visited[sv] = true;
    q.push(sv);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(adj[front].size() == 0) return;
        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    if(parent.find(ev) == parent.end()) return;
    ans.push_back(ev);

    while (ev != sv ) {
        ev = parent[ev];
        ans.push_back(ev);
    }
}


int main() {
    int n ; cin >> n;
    int e ; cin >> e;
    vector<int>adj[n+1];
    for(int i = 0; i < e; i++){
        int f , s;
        cin >> f >> s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }

    int sv; cin >> sv;
    int ev; cin >> ev;
    vector<bool>visited(n, false);
    vector<int>ans;
    bfs(adj,visited,n,ans,sv,ev);
    if( visited[ev]){
        for(auto i: ans) cout << i << " ";
    }else cout << " ";
}
