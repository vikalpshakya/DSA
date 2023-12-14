/*
Steps:
    1. Calculate indegree of all the vertices
    2. Push all the vertices with indegree 0, into the queue
    3. [While !q.empty()] Store and pop front vertex ,then:
        ~ Push it into the TopoSort vector
        ~ Traverse in the adj list,then
            ~ Decrement the indegree of its ajdacent vertices by 1
            ~ If indegree of any vertex become 0, push that vertex into the queue
    4. Stop once the queue is empty. Noe print the topoSort vector
*/     

// Time complexity: O(V+E), Space complexity: O(V) 


class Solution {
	public:
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
};
