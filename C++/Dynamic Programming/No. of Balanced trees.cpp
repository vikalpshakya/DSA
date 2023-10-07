/*
Time complexity: O(2^N)
Space complexity: O(N)
where N is the final height of the binary tree
*/
int balancedBTs(int n) {
  if (n <= 1) 
    return 1;
  
  int mod = 1e9 + 7;
  int x = balancedBTs(n - 1);
  int y = balancedBTs(n - 2);
  long long int temp1 = ((long long int)x * x) % mod; // Number of BTs made by attaching subtrees of height (n - 1) at both sides of root
  long long int temp2 = (2 * (long long int)x * y) % mod; // Number of BTs made by attaching subtrees of heights (n - 1) and (n - 2) at each side of root
  long long int ans = (temp1 + temp2) % mod;
  return ans;
}
