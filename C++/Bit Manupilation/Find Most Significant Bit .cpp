#include<bits/stdc++.h>
using namespace std;

int findMSB_app1(int n) {       // Naive approach 
      int count = -1;
    
      while(n != 0) {
          n /= 2;
          count++;
      }
  
      return (1 << count);
}

/*
  Intution: making all the binary digits to 1 .
    For example: If n = 17 ( 1 0 0 0 1)
    So after making all it's digits as one , we would get as ( 1 1 1 1 1 )
    Now we will add 1 into it so that we get 1 0 0 0 0 0 
    Now we can see than the 2nd bit from the left is our MSB of the original number 
    So , we'll simply right shif the number by 1 
    and hence the resulting number would be our MSB [ to find the position of MSB

*/

int findMSB_app2(int n) {      // Efficient approach
  
    for(int i = 1; i <= 16; i*=2){
        n |= n >> i;
    }
  
    n = n + 1;
    return n >> 1;
  
}

int main(){
  
  int n; cin >> n;
  
  cout << findMSB_app1(n) << endl ;
  cout << findMSB_app2(n) << endl;
        
}


