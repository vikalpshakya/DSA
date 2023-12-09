// problem link : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
private:
  // Time complexity : O(n), Space complexity: O(n)

    bool bfs(vector<bool>& visited, vector<int>adj[], int sv){
        visited[sv] = true;
        queue<pair<int,int>>q;
        q.push({sv,-1});
        while(!q.empty()){
            int parent = q.front().second;
            int front = q.front().first;
            q.pop();
            for(auto i : adj[front]){
                if(visited[i] && i != parent) return true;
                else if(!visited[i]){
                    visited[i] = true;
                    q.push({i,front});
                }            
                
            }
        }
        return false;
    }
    
    bool dfs(vector<bool>& visited, vector<int> adj[], int sv, int parent){
        visited[sv] = true;
        for(auto i : adj[sv]){
            if(visited[i] && i != parent) return true;
            else if(!visited[i]){
                bool ans = dfs(visited, adj, i, sv);
                if(ans) return true;
            }
        }
        return false;
    }
    
  public:
  
    bool isCycle(int n, vector<int> adj[]) {
        vector<bool>visited(n,false);
        // for disconnected component
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bool yes = dfs(visited, adj, i, -1);
                if(yes) return true;
            }
        }
        return false;
    }
};
