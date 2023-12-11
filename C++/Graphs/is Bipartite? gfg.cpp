// problem link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

// Time complexity: O(V+2E), Space complexity: O(V)
class Solution {
private:
    bool bfs(int n, vector<int>adj[], vector<int>& colored, int sv){
        queue<int>q;
        q.push(sv);
        colored[sv] = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i : adj[front]){
                if(colored[i] == -1){
                    colored[i] = !colored[front];
                    q.push(i);
                }
                else if(colored[front] == colored[i])
                    return false;
                
            }
        }
        return true;
    }
    
    bool dfs(int n , vector<int>adj[], vector<int>& colored, int sv, int col){
        colored[sv] = col;
        for(auto i : adj[sv]){
            if(colored[i] == -1){
                bool ans = dfs(n, adj, colored, i, !col);
                if(!ans) return false;
            }
            else if(colored[i] == col)
                return false;

        }
        return true; 
    }
    
    
public:
	bool isBipartite(int V, vector<int>adj[]){
        vector<int>colored(V,-1);
    // For disconnected componenets 
	    for(int i = 0; i < V; i++){
	        if(colored[i] == -1 && !dfs(V, adj, colored, i, 0) )
	            return false;
	    }
	    return true;
	}
};

