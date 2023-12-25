
#include<iostream>
using namespace std;

int main(){
  
  int n; cin >> n;
  int i; cin >> i;
  
  // Creating a mask and performing logical OR with 1 at ith position 
  
  n = n | (1 << i) ;
  
  cout << "Number after making ith bit to 1 :  " << n;

}
