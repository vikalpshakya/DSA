/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
 
// Time complexity: O(4^(n^2)), Space complexity: O(n^2)


#include<bits/stdc++.h>
using namespace std;
void printSol(vector<vector<int>>&ans , int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cout << ans[i][j] << " ";
	}
	cout << endl;
}

void solve(vector<vector<int>>& arr,vector<vector<int>>&ans,int row,int col,int n){
	if( row == n-1 && col == n-1){
		ans[row][col] = 1; 
        printSol(ans, n);
        return;
	}

	if(row >=n || col >= n || row < 0 || col < 0 || arr[row][col] == 0 || ans[row][col] == 1 ) return ;
	ans[row][col] = 1;

	solve(arr,ans,row-1,col,n);
	solve(arr,ans,row+1,col,n);
	solve(arr,ans,row,col-1,n);
	solve(arr,ans,row,col+1,n);
	ans[row][col] = 0;
}



int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	vector<vector<int>>ans (n,vector<int>(n,0));
	solve(arr,ans,0,0,n);

	return 0;
}
