// problem link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

class Solution{

// Time complxity: O(V+E), Space complexity: O(n)

class Solution {
  private:
    bool dfs(int n, vector<int> adj[], vector<bool>& visited, vector<bool>& inPath, int sv){
        visited[sv] = true;
        inPath[sv] = true;
        for(auto i : adj[sv]){
            if(!visited[i]){
                if(dfs(n,adj,visited,inPath,i)){
                    return true;
                }
            }
            else if(inPath[i]){
                return true;
            }
        }
        
        inPath[sv] = false;
        return false;
    }
     
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<bool>visited (n,false);
        vector<bool>inPath  (n,false);
        
        for(int i = 0; i < n; i++){
            if(!visited[i])
                dfs(n,adj,visited,inPath,i);
        }
        
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(!inPath[i])
                ans.push_back(i);
        }
        return ans;
    }
};
