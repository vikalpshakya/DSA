
#include<bits/stdc++.h>
using namespace std;

void bfs(int src, vector<bool>& visited, vector<int> adj[] ){
    queue<int> q;
    q.push(src);
    while(!q.empty()){ //q.size() > 0
        int node = q.front();
        cout << node << " ";
        q.pop();
        visited[node] = true;
        for(int child: adj[node]){
            if(!visited[child]){
                q.push(child);
            }
        }
    }
    cout << endl;
}

int main(){
    int v; cin >> v; // 8 used to store the no. of vertexes or no of nodes
    vector<int> adj[v + 1]; // 8 + 1
    int e; cin >> e; // 9 no of edges
    for(int i = 0; i < e; i++){ // for taking the input of e edges resp.
        int u, v; cin >> u >> v;
        // u->v;
        // v->u
        // 8->6
        // 6->8
        // adj[8] -> {4, 3, 1};
        adj[u].push_back(v);
        // adj[8] -> {4, 3, 1, 6};
    }
    vector<bool> visited(v + 1, false);
    for(int i = 0; i < v + 1; i++){
        if(!visited[i]){
           bfs(i, visited, adj );
        }
    }
    return 0;
}
