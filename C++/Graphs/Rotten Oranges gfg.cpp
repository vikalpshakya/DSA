// problem link :   https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

// Time complexity: O(n*m), Space complexity: O(n*m) 


class Solution{
private:
    int bfs(queue<pair<pair<int,int>,int>>& q, vector<vector<bool>>& visited, vector<vector<int>>& grid, int delRow[], int delCol[]){
        int n = grid.size();
        int m = grid[0].size();        
        int tm = 0; // time
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            tm = q.front().second; // time
            q.pop();
            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >=0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == 1){
                    visited[nRow][nCol] = true;
                    q.push({{nRow,nCol},tm+1});
                }
            }
        }
        return tm;
    }

public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;  // {{row,col},time};

        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        int ans = bfs(q, visited, grid, delRow, delCol);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !visited[i][j])
                    return -1;
            }
        }
        return ans;
    }
};
