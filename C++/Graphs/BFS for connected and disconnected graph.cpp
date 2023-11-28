#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &edges, int n, vector<bool>&visited, int start,vector<int>&ans){
    queue<int>q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(int i = 0; i < n ; i++){
            if(edges[front][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return ;
}

vector<int> BFS(vector<vector<int>>& edges, int n){
    vector<bool>visited(n,false);
    vector<int>ans ; // for storing the bfs traversal
    for(int i = 0; i < n; i++){
        if(!visited[i]) {
            bfs(edges,n,visited,i,ans);
        }
    }
    return ans;
}


int main(){
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges( n , vector<int> (n, 0));
    for(int i = 0; i < e; i++){
        int s ,f;
        cin >> s >> f;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
    vector<int>res = BFS(edges,n);
    for(auto i: res) cout << i << " ";
}
