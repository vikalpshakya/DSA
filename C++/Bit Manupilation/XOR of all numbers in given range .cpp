/*

To find XOR of all numbers in a given range[L-R] : 
  XOR(L-1) ^ XOR(R) , [ Where XOR(L-1) means XOR of all numbers from 1 to L-1]

*/


#include<iostream>
using namespace std;

int findXOR (int n) {
    // Returns the XOR of all the values from 1 to n
  if( n % 4 == 0) return n;
  if( n % 4 == 1) return 1;
  if( n % 4 == 2) return n+1;
  if( n % 4 == 3) return 0;
  
  return 0;
}

int main() {
  int start , end;
  cin >> start >> end;
  
  int ans = findXOR(start - 1) ^ findXOR(end);
  cout << ans;

}
