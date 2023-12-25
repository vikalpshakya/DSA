// https://cp-algorithms.com/algebra/bit-manipulation.html

#include<iostream>
using namespace std;

int unset(int n, int i)  { 
    n = n & (~(1 << i)) ;
    return n;
}

int set(int n, int i) { 
    n = n | (1 << i);
    return n;
}

int flip (int n , int i) {
    n = n ^ (1 << i) ;
    return n;
}

int main(){ 
  
  int n; cin >> n;
  int i; cin >> i; 
  
  cout << "Number after setting the ith bit: " << set(n,i) << endl;
  
  cout << "Number after clearing the ith bit: " << unset(n,i) << endl;
  
}
