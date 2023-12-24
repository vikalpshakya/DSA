// problem link: https://www.codingninjas.com/studio/problems/shortest-path-in-dag_8381897
// Time Complexity: O(N+E), Space Complexity: O(N+E)

void getTopo(int n, vector<pair<int, int>> adj[], vector<bool>& visited, stack<int>& st, int sv) {
    visited[sv] = true;
    for (auto i : adj[sv]) {
        int v = i.first;
        if (!visited[v])
            getTopo(n, adj, visited, st, v);
    }
    st.push(sv);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int f = edges[i][0];
        int s = edges[i][1];
        int w = edges[i][2];
        adj[f].push_back({s, w});
    }

    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            getTopo(n, adj, visited, st, i);
    }

    vector<int> distance(n, INT_MAX); 
    distance[0] = 0;

    while (!st.empty()) {
        int top = st.top();
        st.pop();

        if (distance[top] != INT_MAX) {
            for (auto it : adj[top]) {
                int v = it.first;
                int w = it.second;

                if (distance[top] + w < distance[v]) {
                    distance[v] = distance[top] + w;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(distance[i] == INT_MAX)
            distance[i] = -1;
    }
    return distance;
}




