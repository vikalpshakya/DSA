#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std; 
bool isSubSequence(string str1,string str2, int m, int n)
{
 
    // Base Cases
    if (m == 0)
        return true;
    if (n == 0)
        return false;
 
    // If last characters of two
    // strings are matching
    if (str1[m - 1] == str2[n - 1])
        return isSubSequence(str1, str2, m - 1, n - 1);
 
    // If last characters are
    // not matching
    return isSubSequence(str1, str2, m, n - 1);
}
signed main(){
  ll tt = 1;
  // cin >> tt;
  while(tt--) {
    string a; cin >> a;
    string b; cin >> b;
    int n = a.size(), m = b.size();
    isSubSequence(b,a,m,n) ? cout << "YES\n" : cout << "NO\n";

 
  }
  return 0;
}
