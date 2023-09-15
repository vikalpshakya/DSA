#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& arr){
    for(int i: arr){
    cout << i << " ";
    }
    cout << "\n";
}

void heapify(vector<int>& arr, int n, int i){
    int parent = n;
    // because we are follo. zero based
    int lc = 2*parent + 1;
    int rc = 2*parent + 2;
    if(lc < i and arr[parent] < arr[lc]){
        parent = lc;
    }
    if(rc < i and arr[parent] < arr[rc]){
        parent = rc;
    }
    if(parent != n){
        swap(arr[parent], arr[n]);
    // v.v imp step
    heapify(arr, parent, i);
    }
}

void buildHeap(vector<int>& arr){
    int n = arr.size();
    for(int i = (n / 2) - 1; i >= 0; i--){
    // (array, from , to)
        heapify(arr, i, n);
    }
}

void heapSort(vector<int>& arr){
    int n = arr.size();
    //step 1 to build a heap
    buildHeap(arr);
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "before sorting ";
    print(arr);
    heapSort(arr);
    cout << "after sorting ";
    print(arr);
    return 0;
}
