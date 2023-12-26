#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return n && !(n & (n - 1));
}

int main(){  
  int n; cin >> n;
  cout << isPowerOfTwo(n) << endl;

}
