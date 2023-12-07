// problem link : https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

// Time complexity: O(n^2), Space complexity: O(n^2)
class Solution{
private:
      void bfs(vector<vector<char>>& grid,vector<vector<bool>>&visited, int row, int col){
          queue<pair<int,int>>q;
          visited[row][col] = true;
          q.push({row,col});
          int n = grid.size();
          int m = grid[0].size();
          while(!q.empty()){
              int rw = q.front().first;
              int cl = q.front().second;
              q.pop();
              for(int delR = -1; delR <= 1; delR++){            // for traversing all neighbour nodes of a block using a derived formula
                  for(int delC = -1; delC <= 1; delC++){
                      int nRow = rw + delR;
                      int nCol = cl + delC;
                      if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && !visited[nRow][nCol]){
                          visited[nRow][nCol] = true;
                          q.push({nRow,nCol});
                      }
                  }
              }
          }
          
      }
    
    
      int bfsComp(vector<vector<char>>& grid){
          int n = grid.size();
          int m = grid[0].size();
          vector<vector<bool>>visited(n,vector<bool>(m,false));
          int count = 0;
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(!visited[i][j] && grid[i][j] == '1'){
                      bfs(grid,visited,i,j); // i == row , j == col 
                      count ++;
                  }
              }
          }
          return count;
      }
    
  public:
    int numIslands(vector<vector<char>>& grid) {
       bfsComp(grid);
    }
};
