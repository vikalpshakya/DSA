
//  Time Complexity: O(N+2E), Space Complexity: O(N)

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(int i = 0; i < M; i++){
        
            int f = edges[i][0];
            int s = edges[i][1];
            
            adj[f].push_back(s);
            adj[s].push_back(f);
            
        }
        
        vector<int>distance(N,INT_MAX);
        distance[src] = 0;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i : adj[front]) {
                if(distance[front] + 1 < distance[i]) {
                    distance[i] = distance[front] + 1;
                    q.push(i);
                }
            }
        }
        
        for(auto& i : distance) {
            if(i == INT_MAX)
                i = -1;
        } 
        
        return distance;
    }
        
};
