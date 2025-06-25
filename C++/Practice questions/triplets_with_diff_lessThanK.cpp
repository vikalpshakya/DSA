#include<bits/stdc++.h>
using namespace std;
int n, d; 


int brute(vector<int>&vec) { // O(n^3)
    int count = 0;

    for(int i = 0; i < n-2; i++) {
        for(int j = i+1; j < n-1; j++) {
            for(int k = j+1; k < n; k++) {

                if(vec[k]-vec[j] <= d && vec[k]-vec[i] <= d && vec[j]-vec[i] <= d) count++;

            }
        }
    }
    return count;
}


int countTriplets(vector<int>&vec) { // TC: O(n)
    
    int head = -1, tail = 0, maxVal = vec[0];
    int ans = 0;

    while(tail < n) {
        while(head+1 < n && vec[head+1] <= d+vec[tail]) {
            head++;
        }
        if(head-tail >= 2) {
            int len = head-tail-1;

            ans += len*(len+1)/2;   // add all pairs in the range too
        }

        tail++;
        maxVal = vec[tail]+d;
    }
    return ans;

}

int main() {
    cin >> n >> d;
    vector<int>vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    cout << countTriplets(vec) << endl;
    cout << brute(vec) << endl;
}