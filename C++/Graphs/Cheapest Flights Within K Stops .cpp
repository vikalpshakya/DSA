// Time complexity: O(E*V) , Space complexity : O(E*V) 

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>distance(n,INT_MAX);
        distance[src] = 0;

        queue<pair<int,pair<int,int>>> q;
        // {stops, { node, cost}}
        q.push({0,{src,0}});

        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if(stops > k) continue;

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if( stops <= k && cost + wt < distance[adjNode] ) {
                    distance[adjNode] = cost + wt;
                    q.push({stops + 1, {adjNode,cost+wt}}); 
                }
            }

        }

        if(distance[dst]==INT_MAX)
            return -1;

        return distance[dst];
    }
