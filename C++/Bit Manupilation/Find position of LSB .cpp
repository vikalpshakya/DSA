// Intution : Shift the lsb and maintaining a count variable untill it reaches the 0th position

#include<iostream>
using namespace std;

int main() {
  int n; cin >> n;
  int pos = 0;
  while(n != 0) {
    if(n & 1)
        break;
     pos++;
     n = n >> 1;
  }
  
  cout << "Positions of LSB is : " << pos ;

  return 0;
}
