
// Here we have used dijsktra algorithm . 

// Time complexity: O(E*LogV ) + O(n) , Space complexity: O(n) 



#include<bits/stdc++.h>
using namespace std;

#define PQ priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> 


    vector <int>getPath(int n, vector<pair<int,int>>adj[], int sv) {
        
        vector<int>distance(n+1,INT_MAX);
        distance[sv] = 0;

        vector<int>parent(n+1);
        for(int i = 1; i <= n; i++) parent[i] = i;
        
        PQ pq;
        pq.push({0,sv});
        
        while(!pq.empty()) {
            
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]) {
                
                int adjNode = it.first;
                int distWt = it.second;
                
                if(distance[adjNode] > distWt + distance[node]){
                    distance[adjNode] = distWt + distance[node];
                    pq.push({distance[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(distance[n] == INT_MAX) return {-1}; // Path not found 
        vector<int>path;
        int node = n;
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(node);
        reverse(path.begin(),path.end());
        return path;
        
    }


int main() {
    int n; cin >> n; 
    int m; cin >> m;
    
    vector<pair<int,int>>adj[n+1];
    
    for(int i = 1; i <= m; i++) {
        int f; cin >> f;
        int s; cin >> s;
        int wt; cin >> wt;
        
        adj[f].push_back({s,wt});
    }
    
    vector<int>shortestPath = getPath(n,adj,1);
    
    for(auto i : shortestPath) 
        cout << i << " " ;
        
    return 0;
    
}

