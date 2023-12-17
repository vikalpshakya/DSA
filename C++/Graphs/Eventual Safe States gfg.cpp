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

//----    ---------APPROACH 2 USING KAHN'S ALGO AND TOPO SORT ------------------------//
// SUBMITTED ON LEETCODE
/*
Intution: Nodes which are part of any cycle would be considered as unsafe nodes , 
          Hence we would find all the safe nodes ie.. which are not involved in cycle and return them.
          The reason behind reversing the graph is that. because if we dont reverse then we wont be able to 
          traverse the graph since we are working here on outgoing edges . 
*/


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        for(int i = 0; i < n; i++){
            for(auto j : graph[i])
                adj[j].push_back(i);
        }

        vector<int>indeg(n,0);

        for(auto i: adj){
            for(auto j: i)
                indeg[j]++;
        }
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto i: adj[front]){
                indeg[i]--;
                if(indeg[i] == 0)
                    q.push(i);
            }
        }

        vector<int>safeNodes;
        // Nodes whose indegree == 0 means they are not part on any cycle
        for(int i = 0; i < n; i++){
            if(indeg[i] ==  0)
                safeNodes.push_back(i);
        }
        return safeNodes;

    }
};
