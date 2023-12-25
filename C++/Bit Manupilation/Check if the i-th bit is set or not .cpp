
#include<iostream>
using namespace std;

int main(){
  
  int n; cin >> n;
  int i; cin >> i;
  
  // Creating a mask and performing logical AND with 1 at ith position and rest as 0
  
  if(n & (1 << i)) cout << "Yes, The bit is set";
    
  else cout << "NO, The bit is not set ";
  
}
