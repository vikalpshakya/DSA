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
   

THIS LOGIC WILL WORK ONLY FOR DGA (DIRECTED,ALICYCLIC GRAPHS)
THEREBY , TO CHECK THE PRESENCE OF THE CYCLE WE CAN USE A VISITED COUNT ,
  AND INCREMENT IT INSIDE THE WHILE LOOP .
  AT THE END IF COUNT == N, THEN IT'S A D.A.G, ELSE WE CAN SAY THAT THE GIVEN GRAPH HAS A CYCLE 
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
