// ---------------APPROACH 1[ Recursive ] ----------------//

// ----Time Complexity: O(3^(m*n)), Space complexity: O(max(m,n))---------//

int solve_rec(int ** input , int m , int n , int i , int j){
	if(i >= m || j >= n) return INT_MAX;
	if(i == m-1 && j == n-1) return input[i][j];
	int down = solve_rec(input,  m,  n, i+1 ,  j);
	int right = solve_rec(input,  m,  n,  i,  j+1 );
	int daig = solve_rec(input,  m,  n,  i+1,  j+1);
	return input[i][j] + min({down,right, daig});
}
// ---------------APPROACH 2[ DP + Memoisation ] ----------------//

// ----Time Complexity: O(m*n), Space complexity: O(max(m,n))---------//

int solve_mem(int ** input, vector<vector<int>>&dp,  int m , int n , int i , int j) {
	// if(i >= m || j >= n) return INT_MAX;
	
	if(i == m-1 && j == n-1) return input[i][j];
	if(dp[i][j] != -1 ) return dp[i][j];
	int down = solve_mem(input, dp, m,  n, i+1 ,  j);
	int right = solve_mem(input, dp, m,  n,  i,  j+1 );
	int daig = solve_mem(input,dp,  m,  n,  i+1,  j+1);
	return dp[m][n] = input[i][j] + min({down,right, daig});
}

int solve_memo(int ** input ,int m , int n) {
	vector<vector<int>>dp(m+1,vector<int>(n+1, -1));
	return solve_mem(input, dp,  m, n, 0,  0);
}

// ---------------APPROACH 3[ DP + Tabulation] ----------------//

// ----Time Complexity: O(m*n), Space complexity: O(max(m,n))---------//

// int solve_tab ( int ** input , int m, int n ) { 
// 	vector<vector<int>>dp(m+1,vector<int>(n+1, 0));
// 	for(int  )

// 	for(int = 0; i < input)
// }




int minCostPath(int **input, int m, int n)
{
	return solve_memo(input,m,n);
}



