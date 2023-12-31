
// Using Set 

class Solution {
    
	public:

    vector <int> dijkstra(int v, vector<vector<int>> adj[], int S) {
        vector<int>distance(v,INT_MAX);
        set<pair<int,int>> st;
        
        
        distance[S] = 0;
        
        st.insert({0,S});
        
        while(!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto i : adj[node]) {
                
                int adjNode = i[0];
                int distWt = i[1];
                
                if(distance[adjNode] > distWt + distance[node]){
                    if(distance[adjNode] != INT_MAX)
                        st.erase ({distance[adjNode],adjNode});
                    distance[adjNode] = distWt + distance[node];
                    st.insert({distance[adjNode], adjNode});
                }
            }
        }
        
        return distance ;
        
    }
};


--------------------------------------USING PRIORITY QUEUE ----------------------------------------------

#define PQ priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> 

class Solution {
    
	public:

    vector <int> dijkstra(int v, vector<vector<int>> adj[], int S) {
        vector<int>distance(v,INT_MAX);
        PQ pq;
        
        distance[S] = 0;
        
        pq.push({0,S});
        
        while(!pq.empty()) {
            
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]) {
                
                int adjNode = it[0];
                int distWt = it[1];
                
                if(distance[adjNode] > distWt + distance[node]){
                    distance[adjNode] = distWt + distance[node];
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        
        return distance ;
        
    }
};
