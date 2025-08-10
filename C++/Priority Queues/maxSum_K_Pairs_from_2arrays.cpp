#include<bits/stdc++.h>
using namespace std;

// question link: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1


vector<int> maxCombinations(int n ,int k, vector<int>&a, vector<int>&b) {
        
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({a[0]+b[0],{0,0}});
        
        set<pair<int,int>>st;
        
        // int n = a.size();
        vector<int>ans;
        // ans.push_back(pq.top().first);
        
        for(int i = 0; i < k; i++) {
           ans.push_back(pq.top().first);
           
           int l = pq.top().second.first;
           int r = pq.top().second.second;
           
           pq.pop();
           
           if(l+1 < n && st.find({l+1,r}) == st.end()){
                pq.push({a[l+1]+b[r],{l+1,r}});
                st.insert({l+1,r});
           }
                
            if(r+1 < n && st.find({l,r+1}) == st.end()){
                pq.push({a[l]+b[r+1],{l,r+1}});
                st.insert({l,r+1});
            }

        }
        
        return ans;
        
    }



int main() {
    int n, k;
    cin >> n >> k;

    vector<int>v1(n),v2(n);
    for(int i = 0; i < n; i++) {
        cin >> v1[i] >> v2[i];
    }

    vector<int>ans = maxCombinations(n,k,v1,v2);
    
    for(auto it: ans) cout << it << endl;

}