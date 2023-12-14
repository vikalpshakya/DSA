// problem: https://www.geeksforgeeks.org/problems/topological-sort/1

// Time complexity: O(V+E), Space complexity: O(V)
class Solution {
  private:
      void dfs (vector<int>adj[], vector<bool>& visited, stack<int>& st, int sv){
          visited[sv] = true;
          for(auto i: adj[sv]){
              if(!visited[i])
                  dfs(adj,visited,st,i);
          }
          st.push(sv);
      } 

  	public:
  	//Function to return list containing vertices in Topological order. 
  	vector<int> topoSort(int n, vector<int> adj[]) {
  	    vector<bool>visited(n,false);
  	    stack<int>st;
  	    for(int i = 0; i < n; i++){
  	        if(!visited[i]){
  	            dfs(adj,visited,st,i);
  	        }
  	    }
  	    vector<int>ans;
  	    while(!st.empty()){
  	      ans.push_back(st.top());
  	      st.pop();
  	    }
  	    return ans;
  	}
};
