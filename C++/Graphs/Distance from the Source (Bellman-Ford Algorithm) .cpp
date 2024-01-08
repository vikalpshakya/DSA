// Time Complexity: O(V*E).
// Space: O(V).

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        int n = edges.size();
        vector<int>distance(V,1e8);
        
        distance[S] = 0;
        
        for(int i = 0; i < V-1; i++) {
 
            for(auto it: edges) {
                int f  = it[0];
                int s  = it[1];
                int wt = it[2];
                
                if(distance[f] != 1e8 && distance[s] > wt + distance[f])
                    distance[s] = wt + distance[f];
                
            }
            
        }
        
        for(auto it: edges) {
                int f  = it[0];
                int s  = it[1];
                int wt = it[2];
                
                if(distance[f] != 1e8 && distance[s] > wt + distance[f])
                    return {-1};
        }
        
        return distance;
    }
};
