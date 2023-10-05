// Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
// 1.) Subtract 1 from it. (n = n - ­1) ,
// 2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
// 3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  

// ---------------APPROACH 1 ----------------//

// ----Time Complexity: O(3^n), Space complexity: O(3^n)
int countMinStepsToOne(int n){
	if(n <= 3) return 1;
	int a=INT_MAX,b=INT_MAX,c=INT_MAX;
	if(n%2 == 0){
		b = countMinStepsToOne(n/2);
	}
	else if(n %3 == 0){
		c = countMinStepsToOne(n/3);
	}
	else  a = countMinStepsToOne(n-1);

	return 1+ min(a,min(b,c));
}
// ---------------APPROACH 2 [DP+memoisation] ----------------//

// ----Time Complexity: O(n), Space complexity: O(n)---------//
int countMinStepsToOne_mem(int n,vector<int>&dp){
	if(n == 1) return 0;
	if(n <= 3) return 1;
	if(dp[n] != -1) return dp[n];
	int a=INT_MAX,b=INT_MAX,c=INT_MAX;

	if(n%2 == 0){
		b = countMinStepsToOne_mem(n/2,dp);
	}
	if(n %3 == 0){
		c = countMinStepsToOne_mem(n/3,dp);
	}
	a = countMinStepsToOne_mem(n-1,dp);

	dp[n] = 1+ min(a,min(b,c));

	return dp[n];
}
// ---------------APPROACH 3[DP + tabulation] ----------------//

// ----Time Complexity: O(n), Space complexity: O(n)---------//
int countMinStepsToOne_tab(int n){
	vector<int>dp(n+1,0);	//  step 1
	dp[1] = 0;
	dp[2] = 1;			// step 2
	dp[3] = 1;
	for(int i = 4; i <= n; i++){
		int a=INT_MAX,b=INT_MAX,c=INT_MAX;
		// step 3 
		if(i%2 == 0){
			b = dp[i/2];
		}
		if (i % 3 == 0) 
			c = dp[i / 3];

		a = dp[i - 1];

		dp[i] = 1 + min(a, min(b, c));
        }
        return dp[n];	
}
// ----Main Function------//

int countMinStepsToOne(int n){
	vector<int>dp(n+1,-1);
	return countMinStepsToOne_tab(n);
}
