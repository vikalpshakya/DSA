#include <iostream>
using namespace std;


void swapUsingBit(int& a, int& b){
    
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "Numbers before swapping : " << a << " " << b << endl;
    swapUsingBit(a,b);
    cout << "Numbers after swapping: " << a << " " << b << endl;
}
