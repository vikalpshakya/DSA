
/*

Every odd number has his LSB (least significant bit) as 1
So we'll just check the LSB , and if it's 1 then it's odd else the number is even

*/

#include<iostream>
using namespace std;

int main(){
  int n; cin >> n;
  if(n & 1) 
      cout << "The number is odd" << endl;
  else
      cout << "The number is even" << endl;
}
