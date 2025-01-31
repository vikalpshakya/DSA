#include<bits/stdc++.h>
using namespace std;

int subTreeSize[];
bool visited[];

vector<int>adj[];

void dfs(int src) {
   visited[src] = true;
   subTreeSize[src] = 1;

   for(auto v: adj[src]) {
    if(!visited[v]) {
        dfs(v);
        subTreeSize[src] += subTreeSize[v];
    }
   }
   
}
