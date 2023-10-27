#include<bits/stdc++.h>

int solve_rec(int *weights, int *values, int n, int maxWeight,int index){
    if(index >= n) return 0;    // base case
    int take = 0, notTake = 0;
    if(maxWeight - weights[index] >= 0) 
        take = values[index] + solve_rec(weights, values,  n,  maxWeight - weights[index],  index+1);
    notTake = solve_rec(weights, values, n, maxWeight, index+1);
    return max(take,notTake);
}

int solve_mem(int *weights, int *values, int n, int maxWeight,vector<vector<int>>&dp, int index){

    if(index >= n) return 0;    // base case
    if(dp[maxWeight][index] != -1) return dp[maxWeight][index];
    int take = 0, notTake = 0;
    if(maxWeight - weights[index] >= 0) 
        take = values[index] + solve_mem(weights, values,  n,  maxWeight - weights[index], dp,  index+1);
    notTake = solve_mem(weights, values, n, maxWeight, dp, index+1);
    return dp[maxWeight][index] =  max(take,notTake);    
}

int memoization(int *weights, int *values, int n, int maxWeight) {
    vector<vector<int>> dp(maxWeight + 1, vector<int>(n + 1, -1));
    return solve_mem(weights, values, n, maxWeight, dp, 0);
}

int knapsack(int *weights, int *values, int n, int maxWeight){
    int index = 0;
	// return solve_rec(weights, values, n , maxWeight, index);
    return memoization(weights, values, n , maxWeight);
}
// -----------------                                            -------------------//




