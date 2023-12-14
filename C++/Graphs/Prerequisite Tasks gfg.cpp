// Time complexity: O(V+E), Space complexity: O(V)
class Solution {
public:
	bool isPossible(int n,int p, vector<pair<int, int> >& edge) {
	   vector<int>adj[n];
	   for(int i = 0; i < p; i++){
	       int f = edge[i].first;
	       int s = edge[i].second;
           adj[s].push_back(f);
	   }
	   queue<int>q;
	   int count = 0;
	   vector<int>indeg(n,0);
	   for(int i = 0; i < n; i++){
	       for(auto it: adj[i]) {
                indeg[it]++;	           
	       }
	   }
	   for(int i = 0; i < n; i++){
	       if(indeg[i] == 0){
	           q.push(i);
	       }
	   }
	   while(!q.empty()){
	       int front = q.front();
	       q.pop();
	       for(auto i : adj[front]){
	           indeg[i]--;
	           if(indeg[i] == 0)
	            q.push(i);
	       }
	       count++;
	   }
	   
	   return count == n;
	   
	}
};
