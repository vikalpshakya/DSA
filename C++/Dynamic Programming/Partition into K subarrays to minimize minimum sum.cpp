#include<bits/stdc++.h>
using namespace std;

vector<int>vec;
int n,k;

/*  
    Given an array , and a integer 'k' , partition the array into k subarrays 
    such that sum of minimum of each subarray is minimized.

    Eg: 
        n = 5, k = 3 ,
       arr = 1 , 3 , 2 , 5 , 4

    => Optimal answer is = 6 
        partition = [ [1] , [3] , [2,5,4] ] 
                  =  1 + 3 + 2 => 6
*/

// T.C = O(n*n*k)
// SC : O(n*k)

int dp[100][100];

int rec(int idx, int p) {

    // pruining 
    if(p < 0) return 1e4;

    // base case
    if(idx == -1) {
        if(p == 0) return 0;
        else return 1e4;
    }

    if(dp[idx][p] != -1) return dp[idx][p];

    int mini = vec[idx];
    int ans = 1e4;

    for(int i = idx-1; i >= -1; i--) {
        ans = min(ans, rec(i,p-1)+ mini); 

        if(i == -1) continue;
        mini = min(mini,vec[i]);
    }

    return dp[idx][p] = ans;
}



int main() {

    cin >> n >> k;
    vec.resize(n);
    memset(dp,-1,sizeof(dp));

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    cout << rec(n-1,k);

}
