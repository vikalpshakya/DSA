// Time complexity: O(n*k), Space complexity: O(n*k)

vector<int> topoSort(int n, vector<int> adj[]) {
	    vector<int>indegree(n,0);
	    for(int i = 0; i < n; i++){
	        for(auto it : adj[i])
	            indegree[it]++;
	    }
	    
	    queue<int>q;
	    for(int i = 0; i < n; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    vector<int>TopoSort;
	    
	    while(!q.empty()){
	        int front = q.front();
	        TopoSort.push_back(front);
	        q.pop();
	        for(auto i : adj[front]){
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	            
	        }
	    }
	      return TopoSort;
	      
	  }

string getAlienLanguage(vector<string> &words, int k) {
    int n = words.size();
    vector<int>adj[k];
    for(int i = 0; i < n-1; i++){
        string f = words[i];
        string s = words[i+1];
        int len = min(f.size(),s.size());
        for(int j = 0; j < len; j++){
            if(f[j] != s[j]){
                adj[f[j] - 'a'].push_back(s[j] - 'a');
                break;
            }
        }
    }
    vector<int>topo = topoSort(k,adj);
    string ans = "";
    for(auto i : topo){
        ans.push_back(char(i+'a'));
    }
    return ans;

}
