// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

// problem link: https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1


class Solution {
  private:
    bool isValid(int row, int col , int n, int m) {
        if(row >= 0 && row < n && col >= 0 && col < m) 
            return true;
        return false;
    }
    
    
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        int s1 = source.first;
        int s2 = source.second;
        
        if(s1 == destination.first && s2 == destination.second) return 0;
        
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        distance[s1][s2] = 0;
        
        queue<pair<pair<int,int>,int>>q;
        
        q.push({source,0});
        
        int delR[] = {-1,0,1,0};
        int delC[] = {0,1,0,-1};
        
        
        while(!q.empty()) {
            auto top = q.front();
            int i1 = top.first.first;
            int j1 = top.first.second;
            int dist = top.second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newR = delR[i] + i1;
                int newC = delC[i] + j1;
                
                if(isValid(newR,newC,n,m) && grid[newR][newC] != 0){
                    if(newR == destination.first && newC == destination.second) return dist + 1;
                    if(distance[newR][newC] > dist + 1){
                        distance[newR][newC] = dist + 1;
                        q.push({{newR,newC},dist+1});
                    }
                }
                    
            }   
        }
        return -1;
    }
};
