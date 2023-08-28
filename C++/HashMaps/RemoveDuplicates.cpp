#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(n) , Space complexity O(n) 

vector<int>removeDuplicates(int *a , int size){
    vector<int>vec;
    unordered_map<int, bool> map;
    for(int i = 0; i < size; i++){
        if(map.count(a[i])){
            continue;
        }
    map[a[i]] = true;
    vec.push_back(a[i]);
    }
    return vec;
}

int main(){
    int size = 8;
    int arr[size] = {1,2,1,3,3,4,4,5};
    vector<int>output = removeDuplicates(arr,size);
    for(int i = 0; i < output.size(); i++){
        cout << output[i]<<" ";
    }
    cout << endl;
}
