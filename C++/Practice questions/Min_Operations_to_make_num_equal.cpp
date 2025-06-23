#include<bits/stdc++.h>
using namespace std;

const int MAX = 5e6;
vector<bool>isPrime(MAX+1,true);

void factorize(map<int,int>&mp, int x)  {
    for(int i = 2; i <= x; i++) {
        while(x%i == 0) {
            mp[i]++;
            x/=i;
        }
    }
}

int main() {
    int a,b; cin >> a >> b;

    map<int,int>mp1,mp2;
    // mp1 -> stores factors of a
    // mp2 -> stores factors of b
    
    factorize(mp1,a);
    factorize(mp2,b);

    int ans = 0;

    for(auto [num,exp] : mp1) {
        ans += abs(exp - mp2[num]);
    }

    for(auto [num,exp] : mp2) {
        if(!mp1[num]) ans += exp;
    }

    cout << ans << endl;

}