const int mod = 1e9 + 7;

// ----Time complexity: O(2^n), Space complexity: O(n) ---- // 

int balancedBTs(int h) {
    if(h == 0 || h == 1) return 1;
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);
    int temp1 = (int) (( (long) (x) * x) % mod);
    int temp2 = (int) ((2* (long) (x)* y ) % mod);
    int ans = (temp1+temp2) % mod;
    return ans;
    
}
