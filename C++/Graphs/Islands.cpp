/*
An island is a small piece of land surrounded by water .
A group of islands is said to be connected if we can reach
from any given island to any other island in the same
group . Given V islands (numbered from 0 to V-1) and E
connections or edges between islands. Can you count the
number of connected groups of islands.
  */
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<int>adj[], vector<bool>&visited,vector<vector<int>>&res, int sv) {
    queue<int>q;
    vector<int>ans;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return ans;
}

vector<vector<int>> connectedComp(int n, vector<int>adj[]){
    vector<vector<int>>res;
    vector<bool>visited(n,false);
    for(int i = 0; i < n; i++){
        if (!visited[i]) {
            vector<int> v = bfs(n, adj, visited, res, i);
            res.push_back(v);
        }
    }
    return res;
}

int main() {
    int n ; cin >> n;
    int e ; cin >> e;
    vector<int>adj[n+1];
    for(int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    vector<vector<int>>res = connectedComp(n,adj);
    cout << res.size() << "\n";

}
