/*

QUESTION: Given a array of integers, Where all values repeat two times except two intergers, 
          Your task is to find those two integers and print them

*/

// video link : https://www.youtube.com/live/ZwU6wSkepBI?si=TQvmklK7tE7kfbfO Time stamp : 8:45

#include <iostream>
using namespace std;

int LSB(int num) {
    int pos = 0;
    while(num != 0){
        if(num & 1) break;
        pos ++;
        num = num >> 1;
    }
    return pos;
}


pair<int,int> getUniqueTwoNum(int arr[] , int n){
    
    int XOR = 0;
    for(int i = 0; i < n; i++){
        XOR ^= arr[i];
    }
    
    // Now XOR here must be equal to val1 ^ val2
    
    int Lsb = LSB(XOR);
    
    int val1 = 0, val2 = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] & (1 << Lsb)) 
            val1 ^= arr[i];
        else
            val2 ^= arr[i];
    }
    
    pair<int,int>ans;
    ans.first = val1;
    ans.second = val2;
    return ans;
    
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    pair<int,int>ans = getUniqueTwoNum(arr,n);
    cout << "First unique number: " << ans.first << " Second unique number: " << ans.second;
}
