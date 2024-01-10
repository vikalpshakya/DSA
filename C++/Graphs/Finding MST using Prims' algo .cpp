 // Time Complexity: O(ElogV).
 // Auxiliary Space: O(V^2).

class Solution
{
	public:

    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        // { distance , node } 
        
        
        vector<bool>inMst(n,false);
        
        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(inMst[node]) continue;
                sum += dist;
                inMst[node] = true;
            
            
            for(auto it : adj[node] ) {
                int adjNode = it[0];
                int wt = it[1];
                if(!inMst[adjNode])
                    pq.push({wt,adjNode});
            }
            
        }
        return sum;
    }
};
