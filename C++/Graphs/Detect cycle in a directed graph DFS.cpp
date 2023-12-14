    // Time Complexity: O(V+E), Space complexity: O(V)
class Solution{
private:
    bool dfs(int n, vector<int>adj[],vector<bool>& visited, vector<bool>& inPath, int sv){
        visited[sv] = true;
        inPath[sv] = true;
        for(auto i : adj[sv]){
            if(!visited[i]){
                inPath[i] = true;
                if(dfs(n,adj,visited,inPath,i)) return true;
            }
            else if(inPath[i])
                return true;
            
        }
        inPath[sv] = false;
        return false;
    }
    
    
    
  public:
    bool isCyclic(int n, vector<int> adj[]) {
        vector<bool>visited(n,false);
        vector<bool>inPath(n,false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(n,adj,visited,inPath,i))
                    return true;
            }
        }
        return false;
    }
};
