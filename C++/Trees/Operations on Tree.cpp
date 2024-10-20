#include<bits/stdc++.h>
#define pb push_back
using namespace std; 

/*

1. isLeaf ? 
2. depth ? 
3. parent ? 
4. no. of children
5. subtree size

*/


int n,m; 
vector<vector<int>>tree;
int isLeaf[1001]; 
int parent[1001];
int depth[1001];
int numChild[1001];
int subtreeSize[1001];

void dfs(int src, int d, int pr) {

    depth[src] = d;
    parent[src] = pr;

    subtreeSize[src] = 1;
    numChild[src] = 0;

    for(auto neigh : tree[src]) {
        if(neigh != pr) {
            numChild[src]++;
            dfs(neigh,d+1,src);
            subtreeSize[src] += subtreeSize[neigh];
        }
    }
    
    if(numChild[src] == 0) isLeaf[src] = 1;

}

void solve() {
   cin >> n >> m;
    tree.resize(n+1);
    memset(isLeaf,false,sizeof(isLeaf));
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs(1,0,-1); // root  is 1

    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": Depth = " << depth[i] << ", Parent = " << parent[i] << ", Subtree Size = " << subtreeSize[i] << ", Is Leaf = " << (isLeaf[i] ? "Yes" : "No") << endl;
    }

}


signed main(){
    solve();
    return 0;
}
