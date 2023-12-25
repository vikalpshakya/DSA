/*

ans for 1 = 1,    [mod = 1]         If we carefully notice the pattern of our answer
    for 2 = 3,    [mod = 2]           we can observe some patter ie..
    for 3 = 0     [mod = 3]           1. For all the numbers who are divisible bye 4 has the answer as itself only
        4 = 4     [mod = 0]           2. If that number gives 1 as num%4 , then it's value would always be 1
       --------------------           3. If the number gives 2 as num%4 , then it's value would be num+1
        5 = 1     [mod = 1]           4. If the number gives 3 as num%4 , then it's value would always be 0
        6 = 7     [mod = 2]
        7 = 0     [mod = 3]
        8 = 8     [mod = 0]
      --------------------
        9 = 1     [mod = 1]
        10 = 11   [mod = 2]
        11 = 0    [mod = 3]
        12 = 12   [mod = 0]
        
  */
// Time Complexity: O(1) , Space complexity: O(1)

#include<iostream>
using namespace std;

int main() {
  int n; cin >> n;
  if( n % 4 == 0) cout << n;
  if( n % 4 == 1) cout << 1;
  if( n % 4 == 2) cout << n+1;
  if( n % 4 == 3) cout << 0;

}

