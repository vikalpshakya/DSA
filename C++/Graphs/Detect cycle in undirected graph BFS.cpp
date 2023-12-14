// Time complexity: O(V+E), Space complexity: O(V)

/*    Intution: TopoSort algo only works on Acyclic directed graphs , 
         So , incase all the nodes couldnt become the part of TopoSort series, then there's definetely present a cycle
*/

class Solution {
  public:
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int>indeg(n,0);
        for(int i = 0; i < n; i++){
            for(auto it: adj[i])
                indeg[it]++;
        }
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        int visited = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i :adj[front]){
                indeg[i]--;
                if(indeg[i] == 0)
                    q.push(i);
            }
            visited++;
        }
        return !(visited == n);
    }
};
