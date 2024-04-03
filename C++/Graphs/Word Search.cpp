// problem link: https://leetcode.com/problems/word-search/
class Solution {
public:
    int delRow[4] = {-1,0,+1,0};
    int delCol[4] = {0,+1,0,-1};
    bool isValid(int n, int m, int x, int y){
        return((x>=0 && x<n) && (y>=0 && y<m));
    }
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int
    wordIndex, int x, int y, int n, int m){
        if(wordIndex== word.size() ) return true;
        visited[x][y]=true;
        bool found=false;
        
        for(int i=0;i<4;i++)
        {
            int newX = x + delRow[i];
            int newY = y + delCol[i];
            if(isValid(n,m,newX,newY) && !visited[newX][newY] && board[newX]
            [newY]==word[wordIndex]){
                found=found | dfs(board,visited,word,wordIndex+1,newX,newY,n,m);
            }
        }
        visited[x][y]=false;
        return found;
    }
    bool hasPath(vector<vector<char>> &board, int n, int m,string word) {
        bool foundPath=false;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        //tavelling on each block of [i,j]
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]) {
                    foundPath=dfs(board,visited,word,1,i,j,n,m); // 0 is the index n word
                    if(foundPath) break;
                }
            }
            if(foundPath) break;
        }
        return foundPath;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m = board[0].size();
        return hasPath(board,n,m,word);
    }
};
