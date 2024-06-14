#include<bits/stdc++.h>
using namespace std;
void merge2array(vector<int>&arr,int s , int e){
    vector<int>output(e-s+1);
    
    int mid  = (s+e)/2;
    int i = s , j = mid+1 , k=0;
    while (i<=mid && j<= e){
        if( arr[i]<arr[j]){
            output[k++]=arr[i++];
        }
        else{
            output[k++]=arr[j++];
        }
    }
    while ( i<=mid){
        output[k++]=arr[i++];
    }
    while ( j<=e){
        output[k++]=arr[j++];
        }
        for (int x = s; x <= e; x++) {
          arr[x] = output[x - s];
        }
}

void mergeSort(vector<int>& arr, int s, int e) {  //3        
    if (s>=e) {
        return ;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s, mid);
    mergeSort(arr,mid+1, e);  
    merge2array(arr,  s, e);
}

int main() {
    int n; cin >> n;
    vector<int>vec(n);
    for(auto &i : vec) cin >> i;

    mergeSort(vec,0,n);

    for(auto i: vec) cout << i << " ";

}
