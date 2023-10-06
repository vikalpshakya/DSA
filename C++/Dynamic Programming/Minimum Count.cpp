// Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

// --------------APPROACH 1 [Recursive] -----------//

// ----Time complexity: O(3^n), Space complexity: O(n)-------//

int minCount_rec(int n) {
	if(n <= 3) return n;
	
	int ans  = INT_MAX;
	for(int i = 1;i*i<=n;i++){
		int curr = 1+minCount_rec(n-(i*i)); 
		ans = min(ans,curr);
	}
	return ans;	  
}
// --------------APPROACH 2 [DP+Memoisation] -----------//

// ----Time complexity: O(n * sqrt(n)), Space complexity: O(n)-------//

int solveMem_helper(int n,vector<int> &dp){
	if(n <= 3) return n;	//step 2:
	
	if(dp[n] != -1) return dp[n];
	int ans  = INT_MAX;
	for(int i = 1;i*i<=n;i++){	// step 3
		int curr = 1+solveMem_helper(n-(i*i),dp); 
		ans = min(ans,curr);
	}
	return dp[n]=ans;
}

int solveMem(int n) {
	//step1:
	vector<int> dp(n+1,-1);
	return solveMem_helper(n,dp);
	  
}
// --------------APPROACH 3 [DP+Tablulation] -----------//

// ----Time complexity: O(n * sqrt(n)), Space complexity: O(n)-------//

int solveTab(int n){
	//step1 :
	vector<int>dp(n+1,0);
	
	//step 2:
	//analyse base case and fill dp array 
	dp[0]=0; dp[1]=1; dp[2]=2; dp[3]=3;

	//step 3:
	//calcuate final ans using for loop
	for(int i=4;i<=n;i++){
		
		int ans  = INT_MAX;
		for(int j = 1;j*j<=i;j++){
			int curr = 0;
			if(i-(j*j)>=0)
				curr = 1+dp[i-(j*j)]; 
		ans = min(ans,curr);
		}
	 dp[i]=ans;

	}
	return dp[n];
}

// ----------MAIN FUNCITON -----------//

int minCount(int n) {

	return solveTab(n);
}

