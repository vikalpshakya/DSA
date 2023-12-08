// problem link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

// Time complexity: O(n*m), Space complexity: O(n*m)

class Solution{
private:
    vector<vector<int>>dfs(int inColor, vector<vector<int>>& ans, vector<vector<int>>& image, int row, int col, int newColor, int delRow[], int delCol[]){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == inColor && ans[nRow][nCol] !=  newColor)
                dfs(inColor, ans, image, nRow, nCol, newColor, delRow, delCol);
        }
        return ans;
    } 
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int inColor = image[sr][sc];
       vector<vector<int>>ans = image;
       int delRow[] = {-1,0,+1,0};
       int delCol[] = {0,+1,0,-1};
       dfs(inColor, ans, image, sr, sc, newColor, delRow, delCol);
       return ans;
    }
};
