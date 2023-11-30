#include <bits/stdc++.h>
using namespace std;

bool bfs(int n, vector<int>adj[], vector<bool>&visited, int sv) {
    queue<int>q;
    vector<int>ans;
    q.push(sv);
    visited[sv] = true;
    ans.push_back(sv);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                ans.push_back(i);
            }
        }
    }
    return ans.size() == n;
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
    vector<bool>visited(n,false);
    vector<int>ans;
    bool yes = bfs(n,adj,visited,0);

    if(yes||n==0) cout << "true\n";
    else cout << "false\n";

}
