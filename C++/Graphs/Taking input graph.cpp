#include<bits/stdc++.h>
using namespace std;

int main(){
    int v; cin >> v; // 8
    vector<int> adj[v + 1]; // 8 + 1 
    int e; cin >> e; // 9
    
    for(int i = 0; i < e; i++){
        int u, v; cin >> u >> v;
    // u->v;
    // 8->6
        adj[u].push_back(v);
    }
    for(int i = 0; i < e; i++){
        for(int j: adj[i]){ // for(int i: arr)
            cout << "edge from " << i << " " << " to " << j << endl;
        }
    }
    return 0;
}
// -------------------------------------------------------------------------------------------------------//
#include<bits/stdc++.h>
using namespace std;

int main(){
    int v; cin >> v; // 8 used to store the no. of vertexes or no of nodes
    vector<pair<int, int>> adj[v + 1]; // 8 + 1
    int e; cin >> e; // 9 no of edges
    for(int i = 0; i < e; i++){ // for taking the input of e edges resp.
        int u, v, wt; cin >> u >> v >> wt;
        // u->v;
        // v->u
        // 8->6
        // 6->8
        // adj[8] -> {4, 3, 1};
        adj[u].push_back({v, wt});
        // adj[8] -> {4, 3, 1, 6};
    }
    /*for(int i = 0; i < e; i++){
        for(int j: adj[i]){ // for(int i: arr)
            cout << "edge from " << i << " " << " to " << j << endl;
        }
    }*/
    for(int i = 0; i < v + 1 ; i++){
        int m = adj[i].size();
        for(int j = 0; j < m; j++){
            cout << "edge from " << i << " " << " to " << adj[i][j].first << " having cost = " << adj[i][j].second << endl;
        }
    }
    return 0;
}
