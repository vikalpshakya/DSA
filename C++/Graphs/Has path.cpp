#include <bits/stdc++.h>
using namespace std;

/*
 Time complexity: O(V + E)
 Space complexity: O(V^2)
*/

bool hasPath(vector<int>adj[], vector<bool>&visited,int st,int start,int end){
        queue<int>q;
        q.push(st);
        visited[st] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i : adj[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return visited[start] && visited[end];
}

int main() {
    int n , e;
    cin >> n >> e;
    vector<int>adjList[n+1];
    for(int i = 0; i < e; i++){
        int f,s;
        cin >> f >> s;
        adjList[f].push_back(s);
        adjList[s].push_back(f);
    }
    int start,end;
    cin >> start >> end;
    vector<bool>visited(n,false);
    if(hasPath(adjList,visited,0,start,end))
        cout << "true\n";
    else cout << "false\n";
}
