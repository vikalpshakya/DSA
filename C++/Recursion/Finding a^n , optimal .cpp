#include <iostream>
using namespace std;

// Time Complexity : O(n), Space Complexity: O(n) [Recursive stack]

int power(int a, int n) {
    
    if( n == 0) return 1;
    
    return a * power(a,n-1);
}

// Time Complexity : O(Logn), Space Complexity: O(Logn) [Recursive stack]

int fastPower(int a, int n) {
    
    if(n == 0) return 1;
    int smallAns = fastPower(a,n/2);
    smallAns *= smallAns;
    
    if(n & 1) {
        return a * smallAns;
    } 
    return smallAns;
}

int main() {
    int a,n;
    cin >> a >> n;
    
    cout << power(a,n) << endl;
    cout << fastPower(a,n) << endl;
}
