// problem link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

class Solution{

// Time complxity: O(V+E), Space complexity: O(n)

private:
    bool dfs(int n, vector<int> adj[], vector<bool>& visited, vector<bool>& inPath, 
    vector<bool>& check, int sv){
        visited[sv] = true;
        inPath[sv] = true;
        check[sv] = false;
        for(auto i : adj[sv]){
            if(!visited[i]){
                if(dfs(n,adj,visited,inPath,check,i)){
                    check[sv] = false;
                    return true;
                }
            }
            else if(inPath[i]){
                check[sv] = false;
                return true;
            }
        }
        
        inPath[sv] = false;
        check[sv] = true;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<bool>visited (n,false);
        vector<bool>inPath  (n,false);
        vector<bool>check   (n,false);
        
        for(int i = 0; i < n; i++){
            if(!visited[i])
                dfs(n,adj,visited,inPath,check,i);
        }
        
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(check[i])
                ans.push_back(i);
        }
        return ans;
    }
};
